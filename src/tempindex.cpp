//============================================================================
// Name        : tempindex.cpp
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================
#ifndef _tempindexcpp
#define _tempindexcpp

#include "tempindex.h"
#include "Config.h"
#include "getfilelist.h"
#include "gzip.h"
#include "parser.h"
using namespace std;

void GenerateTmpIndex()
{
    vector<string> *fileList = getlist(Datafilepath);
    uint32_t docID = 0;
    uint32_t fileID = 0;
    vector<RawPost_item*> *RawPostlist = new vector<RawPost_item*>;
    vector<doc_url_item*> *urlTable=new vector<doc_url_item*>();

    for(int i = 0; i < fileList->size(); i++) {
        string fileName = (*fileList)[i];

        if(fileName.substr(fileName.length()-5, 5) == "index")
        {
            string indexFilePath = fileName;
            string dataFilePath = fileName.substr(0, fileName.length()-5)+"data";

            char *dataFileBuf = ReadGZFile(dataFilePath.data());
            char *indexFileBuf = ReadGZFile(indexFilePath.data());

            if (dataFileBuf == NULL||indexFileBuf==NULL) {
                free(dataFileBuf);free(indexFileBuf);
                dataFileBuf = NULL;indexFileBuf = NULL;
                fileID++;
                continue;
            }

            vector<tuples*> *indexArray = getindex(indexFileBuf);
            vector<char*> *pages = getpage(dataFileBuf, indexArray);
            
            // free the buffer
            free(dataFileBuf);free(indexFileBuf);
            dataFileBuf = NULL;indexFileBuf = NULL;

            // deal with each page
            uint32_t urlPointer = 0;
            for(int j=0;j<pages->size();j++) {
                char *page = (*pages)[j];
                const char *url = (*indexArray)[j]->url.c_str();

                int ret = parser(url,page,RawPostlist,docID);
                uint32_t wordCount = ret<0?0:ret;
                
                doc_url_item *urlItem = new doc_url_item();
                urlItem->docID = docID;urlItem->fileID= fileID;urlItem->startIndex=urlPointer;urlItem->url= url;urlItem->wc = wordCount;
                urlTable->push_back(urlItem);

                urlPointer+=(*indexArray)[j]->length;
                docID++;

                char Tempindexname[128];
                if(RawPostlist->size() > MAX_item_per_tempindex) {
                    sprintf(Tempindexname, Tempindexpath, docID);
                    WriteFile(RawPostlist, Tempindexname, FILEMODE_ASCII);
                    freeRawPostlist(RawPostlist);
                }
                delete []page;page = NULL;
            }
            pages->clear();delete pages;pages = NULL;
            for(int i=0;i<indexArray->size();i++) {
                tuples *indexRecord = (*indexArray)[i];
                delete indexRecord;
                (*indexArray)[i] = NULL;
            }
            indexArray->clear();delete indexArray;indexArray = NULL;
            fileID++;
        }
    }
    fileList->clear();delete fileList;fileList = NULL;
    char Tempindexname[128];
    if(RawPostlist->size() > 0) {
        sprintf( Tempindexname, Tempindexpath, docID);
        WriteFile(RawPostlist,  Tempindexname, FILEMODE_ASCII);
        freeRawPostlist(RawPostlist);
    }
    delete RawPostlist;
    doctablewrite(urlTable,CURRENT_FILEMODE);
    freedoctable(urlTable);
}

void MergeTmpIndex()
{
    system("sort -S 1G -m -k 2f,2f -k 1n,1n /Users/vee/workspace/Inverted_Index/data/temp/*.tempindex -o /Users/vee/workspace/Inverted_Index/data/temp/merge.index");
    system("rm -rf ../data/temp/*.tempindex");
}

void freeRawPostlist(vector<RawPost_item*> *vpost)
{
    for(int i=0;i<vpost->size();i++) {
        RawPost_item *posting = (*vpost)[i];
        delete posting;
        (*vpost)[i] = NULL;
    }
    vpost->clear();
}

void WriteFile(vector<RawPost_item*> *vector, const char* filePath, int mode)
{
    FILE *fp = fopen(filePath, "w+");
    if(fp != NULL) {
        stable_sort(vector->begin(), vector->end(), Cmpbydoc);
        stable_sort(vector->begin(), vector->end(), Cmpbyword);
        for(int i=0; i<vector->size();i++) {
            RawPost_item *posting = (*vector)[i];
            fprintf(fp, "%d %s %d\n", posting->docID, posting->word.c_str(), posting->pos);
        }
        fclose(fp);
    }
}

bool Cmpbydoc(RawPost_item *posting1, RawPost_item *posting2)
{
    return posting1->docID < posting2->docID;
}

bool Cmpbyword(RawPost_item *posting1, RawPost_item *posting2)
{
    return posting1->word < posting2->word;
}

#endif
