//============================================================================
// Name        : invertedindex.h
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================

#ifndef _itableh
#define _itableh

#include <iostream>
#include <string>
#include "table.h"
#include <vector>
#include "Config.h"
using namespace std;

class InvertedTable
{
private:
    int _mode;
    std::string _word;
    char _outputPath[128];
    vector<invert_item *> _invertedList;
    uint32_t _lastDocID;
    uint32_t _counter;
    uint16_t _fileID;
    uint32_t _DocNumLastWord;
    FILE *_fp;
    void write();
public:
    InvertedTable();
    ~InvertedTable();
    void SetFileMode(int mode);
    uint32_t Insert_table(const RawPost_item *rawPostitem);
    uint32_t WriteOutstanding();
    uint16_t GetFileID();
    uint32_t GetDocNumLastWord();
};

void GenerateInvertedIndexFile();

#endif
