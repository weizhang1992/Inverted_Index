//============================================================================
// Name        : tempindex.h
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================
#ifndef _tempindexh
#define _tempindexh

#include "stdint.h"
#include <string>
#include "table.h"
#include <vector>
using namespace std;

void GenerateTmpIndex();

void MergeTmpIndex();

void freeRawPostlist(vector<RawPost_item*> *vector);

void WriteFile(vector<RawPost_item*> *vector, const char* filePath, int mode);

bool Cmpbydoc(RawPost_item  *posting1, RawPost_item  *posting2);

bool Cmpbyword(RawPost_item *posting1, RawPost_item  *posting2);

#endif
