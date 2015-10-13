//============================================================================
// Name        : getfilelist.h
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================
#ifndef  _getfilelist
#define  _getfilelist

#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include "Config.h"
using namespace std;

typedef struct {
    string url;
    int depth;
    int unknown;
    int length;
    char IP[18];
    int port;
    char status[8];

} tuples;

//get file path list
vector<string> *getlist(string path);


//get parsed index file vector from index file
vector<tuples*> *getindex(char *indexfile);

//get page content vector from data file
vector<char*> *getpage(char* datafile, vector<tuples*>* indexArray);

#endif

