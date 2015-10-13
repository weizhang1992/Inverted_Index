//============================================================================
// Name        : main.cpp
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================
#include <iostream>
#include "table.h"
#include "getfilelist.h"
#include<time.h>
#include "gzip.h"
#include "invertindex.h"
#include "tempindex.h"

using namespace std;

int main(int argc, const char * argv[])
{
    time_t start, middle;
    start = time(NULL);
    middle = time(NULL);

    cout<<"Start to generate temporary index files and URLTable."<<endl;
    GenerateTmpIndex();
    cout << "Runtime: " << difftime(time(NULL), middle)<< " Seconds." << endl;
    middle = time(NULL);

    cout<<"Start to merge temporary index files."<<endl;
    MergeTmpIndex();
    cout << "Runtime: " << difftime(time(NULL), middle) << " Seconds." << endl;
    middle = time(NULL);

    cout<<"Start to generate final inverted index files and LexiconTable."<<endl;
    GenerateInvertedIndexFile();
    cout << "Runtime: " << difftime(time(NULL), middle)<< " Seconds." << endl;
    cout<<"All Done!"<<endl;
    cout << "Total Runtime: " << difftime(time(NULL), start) << " Seconds." << endl;
    return 0;
}
