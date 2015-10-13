//============================================================================
// Name        : Config.h
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================
#ifndef _Condfig
#define _Condfig

#define FILEMODE_ASCII 0
#define FILEMODE_BIN 1
#define CURRENT_FILEMODE FILEMODE_BIN

#define MAX_PAGE_LENGTH 33554432
#define MAX_WORD_LENGTH 524288
#define MAX_item_per_tempindex 10000000 // 10 million
#define Maxfinalindexsize 4*1000*1000*1000 // Max size of final inverted index file

#define Tempmergedindex "/Users/vee/workspace/Inverted_Index/data/temp/merge.index"
#define Lexicon_filepath "/Users/vee/workspace/Inverted_Index/data/lexicon.index"
#define Url_Doc_filepath "/Users/vee/workspace/Inverted_Index/data/doc_url.index"
#define Finalfilepath "/Users/vee/workspace/Inverted_Index/data/inverted_%d.index"
#define Tempindexpath "/Users/vee/workspace/Inverted_Index/data/temp/%d.tempindex"
#define Datafilepath "/Users/vee/workspace/Inverted_Index/nz_full"

#endif
