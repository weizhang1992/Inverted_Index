//============================================================================
// Name        : table.cpp
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================
#include "table.h"

void freedoctable(vector<doc_url_item*> *doctable)
{
    for(int i=0;i<doctable->size();i++) {
        delete (*doctable)[i];
        (*doctable)[i] = NULL;
    }
    doctable->clear();
    delete doctable;
    doctable = NULL;
}

void doctablewrite(vector<doc_url_item*> *doctable,int mode)
{
    if(mode == FILEMODE_ASCII) {
        FILE *fp = fopen(Url_Doc_filepath, "w+");
        for(int i=0;i<doctable->size();i++) {
            doc_url_item *doc_url_item =(*doctable)[i];
            fprintf(fp,"%s, %d, %d, %d, %d\n", doc_url_item->url.data(),doc_url_item->docID, doc_url_item->fileID, doc_url_item->startIndex, doc_url_item->wc);
        }
        fclose(fp);
    }
    if(mode == FILEMODE_BIN) {
        FILE *fp = fopen(Url_Doc_filepath, "wb+");
        for(int i=0;i<doctable->size();i++) {
            doc_url_item *doc_url_item =(*doctable)[i];
            uint16_t urlLength = doc_url_item->url.length();
            fwrite(&urlLength, sizeof(uint16_t),1, fp);
            fwrite(doc_url_item->url.data(), sizeof(char), urlLength, fp);
            fwrite(&doc_url_item->docID, sizeof(uint32_t), urlLength, fp);
            fwrite(&doc_url_item->fileID, sizeof(uint16_t), 1, fp);
            fwrite(&doc_url_item->startIndex, sizeof(uint32_t), 1, fp);
            fwrite(&doc_url_item->wc, sizeof(uint32_t), 1, fp);
        }
        fclose(fp);
    }
}

void Writelextable(lex_table *lextable, int mode)
{
    if(mode == FILEMODE_ASCII) {
        FILE *fp = fopen(Lexicon_filepath, "w+");
        for(int i=0;i<lextable->size();i++) {
            lex_item *lexiconItem =(*lextable)[i];
            fprintf(fp,"%s %d %d %d %d\n", lexiconItem->word.data(), lexiconItem->num, lexiconItem->fileID, lexiconItem->invertedPointer, lexiconItem->size);
        }

        fclose(fp);
    }

    if(mode == FILEMODE_BIN) {
        FILE *fp = fopen(Lexicon_filepath, "wb+");
        for(int i=0;i<lextable->size();i++) {
            lex_item *lexiconItem =(*lextable)[i];
            //in binary file, the format is:
            //Lengthof word, word, num, fileID, pointer
            uint16_t wordLength = lexiconItem->word.length();
            fwrite(&wordLength, sizeof(uint16_t),1, fp);    // write the word length
            fwrite(lexiconItem->word.data(), sizeof(char), wordLength, fp);
            fwrite(&lexiconItem->num, sizeof(uint32_t), 1, fp);
            fwrite(&lexiconItem->fileID, sizeof(uint16_t), 1, fp);
            fwrite(&lexiconItem->invertedPointer, sizeof(uint32_t), 1, fp);
            fwrite(&lexiconItem->size, sizeof(uint32_t), 1, fp);
        }

        fclose(fp);
    }
}

