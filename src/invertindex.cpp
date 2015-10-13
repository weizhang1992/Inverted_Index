//============================================================================
// Name        : invertedindex.cpp
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================
#ifndef _Itablecpp
#define _Itablecpp

#include "stdio.h"
#include "invertindex.h"
#include "vbyte.h"
#include "table.h"

using namespace std;

void GenerateInvertedIndexFile()
{
    FILE *mergedIndex = fopen(Tempmergedindex, "r");
    RawPost_item posting;
    char invertedWord[MAX_WORD_LENGTH];
    uint32_t invertedDocID;
    uint32_t invertedPost;
    InvertedTable invertedTable;
    lex_table lextable;
    string lastWord = "";
    uint32_t lastCounter = 0;
    uint32_t count = 0;
    while(fscanf(mergedIndex, "%d %s %d\n", &invertedDocID, invertedWord, &invertedPost) != EOF) {
        posting.docID = invertedDocID;
        posting.word=invertedWord;
        posting.pos = invertedPost;

        // first time
        if(lastWord == "") {
            lastWord = posting.word;
            lex_item *lexiconitem = new lex_item;
            lexiconitem->word = posting.word;
            lexiconitem->invertedPointer = 0;
            lextable.push_back(lexiconitem);
        }

        uint32_t count = invertedTable.Insert_table(&posting);
        if(count > 0) {   // count > 0 means meet new word and there is data written
        	lex_item *lexiconitem = lextable.back();
            lexiconitem->fileID = invertedTable.GetFileID();
            lexiconitem->num = invertedTable.GetDocNumLastWord();
            if(count < lastCounter)  lexiconitem->invertedPointer = 0;
            lexiconitem->size = count - lexiconitem->invertedPointer;

            lexiconitem = new lex_item;
            lexiconitem->word = posting.word;
            lastWord = posting.word;
            lexiconitem->invertedPointer = count;
            lextable.push_back(lexiconitem);
            lastCounter = count;
        }
    }

    count = invertedTable.WriteOutstanding();
    lextable.back()->fileID = invertedTable.GetFileID();
    lextable.back()->num = invertedTable.GetDocNumLastWord();
    if(count > 0 && count < lastCounter)  lextable.back()->invertedPointer = 0;
    lextable.back()->size = count - lextable.back()->invertedPointer;

    Writelextable(&lextable, CURRENT_FILEMODE);
}

InvertedTable::InvertedTable()
{
    _mode = CURRENT_FILEMODE;
    _fileID=0;
    sprintf(_outputPath, Finalfilepath, _fileID);
    _counter = 0;
    _fp = fopen(_outputPath, "a");
}
InvertedTable::~InvertedTable()
{
    fclose(_fp);
}

void InvertedTable::SetFileMode(int mode)
{
    _mode = mode;
}

uint16_t InvertedTable::GetFileID()
{
    return _fileID;
}

uint32_t InvertedTable::GetDocNumLastWord()
{
    return _DocNumLastWord;
}

void InvertedTable::write()
{
    if(_mode == FILEMODE_ASCII) {
        if(_counter > Maxfinalindexsize) {
            // close current file and open a new file
            fclose(_fp);
            _fileID++;
            sprintf(_outputPath, Finalfilepath, _fileID);
            _fp = fopen(_outputPath, "a");
            _counter = 0;
        }
        _DocNumLastWord = (uint32_t)_invertedList.size();
        for(int j=0;j<_invertedList.size();j++) {
        	invert_item *invertitem =_invertedList[j];
            _counter += fprintf(_fp,"%u %u %u ", invertitem->docID, invertitem->freq, invertitem->pos);
            delete invertitem;
            _invertedList[j] = NULL;
        }
        _counter += fprintf(_fp, "\n");
        _invertedList.clear();
        vector<invert_item *> tmp;
        _invertedList.swap(tmp);
    }
    
    if(_mode == FILEMODE_BIN) {
        if(_counter > Maxfinalindexsize) {
            fclose(_fp);
            _fileID++;
            sprintf(_outputPath, Finalfilepath, _fileID);
            _fp = fopen(_outputPath, "a");
            _counter = 0;
        }
        _DocNumLastWord = (uint32_t)_invertedList.size();
        for(int j=0;j<_invertedList.size();j++) {
        	invert_item *invertitem =_invertedList[j];
            uint32_t n;
            uint32_t *np;
            char buf[5];
            
            char *p = buf;
            n = (uint32_t)invertitem->docID;
            np = &n;
            ZVBCODE(np, p);
            int size = (int)(p-buf);
            _counter += sizeof(uint8_t) * fwrite((uint8_t*)buf, sizeof(uint8_t), size, _fp);
            
            p = buf;
            n = (uint32_t)invertitem->freq;
            np = &n;
            ZVBCODE(np, p);
            size = (int)(p-buf);
            _counter += sizeof(uint8_t) * fwrite((uint8_t*)buf, sizeof(uint8_t),size,_fp);
            
            p = buf;
            n = (uint32_t)invertitem->pos;
            np = &n;
            ZVBCODE(np, p);
            size = (int)(p-buf);
            _counter += sizeof(uint8_t) * fwrite((uint8_t*)buf, sizeof(uint8_t),size,_fp);
            delete invertitem;
            _invertedList[j] = NULL;
        }
        _invertedList.clear();
        vector<invert_item *> tmp;
        _invertedList.swap(tmp);
    }
}

uint32_t InvertedTable::WriteOutstanding()
{
    write();
    _invertedList.clear();
    return _counter;
}

uint32_t InvertedTable::Insert_table(const RawPost_item *RawPostitem)
{
    // first insert, new word;
    if(_invertedList.size() == 0) {
        _word = RawPostitem->word;
        invert_item * invertitem = new invert_item;
        _lastDocID = RawPostitem->docID;
        invertitem->actualDocID = RawPostitem->docID;
        invertitem->docID = RawPostitem->docID;
        invertitem->freq =1;
        invertitem->pos = RawPostitem->pos;
        _invertedList.push_back(invertitem);
    } else if (_word != RawPostitem->word){
        //write and free the memory
        write();        
        _word = RawPostitem->word;
        invert_item * invertitem = new invert_item;
        _lastDocID = RawPostitem->docID;
        invertitem->actualDocID = RawPostitem->docID;
        invertitem->docID = RawPostitem->docID;
        invertitem->freq=1;
        invertitem->pos = RawPostitem->pos;
        _invertedList.push_back(invertitem);
        return _counter;
    } else {//insert same word
        // The same doc, compress position
        if(RawPostitem->docID == _lastDocID) {
        	invert_item * invertitem = _invertedList.back();
            invertitem->freq++;
        } else {
            // Different doc, compress the docID
        	invert_item * invertitem = new invert_item;
            _lastDocID = RawPostitem->docID;
            invertitem->actualDocID = RawPostitem->docID;
            // compress docID
            invertitem->docID = (RawPostitem->docID-_invertedList.back()->actualDocID);
            invertitem->freq =1;
            invertitem->pos = RawPostitem->pos;
            _invertedList.push_back(invertitem);
        }
    }
    // 0 means no data written
    return 0;
}



#endif

