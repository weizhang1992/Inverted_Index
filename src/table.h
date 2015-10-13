//============================================================================
// Name        : table.h
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================

#ifndef _tableh
#define _tableh

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Config.h"
using namespace std;

typedef struct{
    uint32_t docID;        // doc id
    uint32_t fileID;       // which data file containing this page
    uint32_t startIndex;   // pointer to the start point in the data file
    uint32_t wc;           //number of words
    string url;            // url
} doc_url_item;

typedef struct {
    std::string word;
    uint32_t num;              // number of docs containing the word
    uint16_t fileID;    	   // the ID of the file containing the invertd index
    uint32_t invertedPointer;  //pointer to the inverted index
    uint32_t size;  		   // size of this list in bytes
} lex_item;

typedef struct {
    uint32_t docID;
    uint32_t actualDocID;
    uint32_t freq;
    uint32_t pos;
} invert_item;

typedef struct {
    uint32_t docID;
    string word;
    uint32_t pos;
} RawPost_item;

typedef std::vector<lex_item *> lex_table;
void freedoctable(vector<doc_url_item*> *doctable);
void doctablewrite(vector<doc_url_item*> *doctable,int mode);
void Writelextable(lex_table *lexable, int mode);

#endif
