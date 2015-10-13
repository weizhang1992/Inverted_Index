//============================================================================
// Name        : getfilelist.cpp
// Author      : Name:Wei Zhang ID:wz707
// Version     : v0.1
// Copyright   : 2015 Wei Zhang. All rights reserved.
// Description : Course Assignment 2 for Web Search Engine Course
//============================================================================

#include <queue>
#include "getfilelist.h"
#include "table.h"
#include "parser.h"

using namespace std;

vector<string> *getlist(string path)
{
    vector<string> *fileList = new vector<string>();
    queue<string> bfs;
    bfs.push(path);
    struct dirent *de;

    while(bfs.size() > 0) {
        string base = bfs.front();
        DIR *dir = opendir(base.c_str());
        if (dir == NULL) continue;
        while((de = readdir(dir))!=NULL) {

            if ((de->d_type == DT_REG||de->d_type == DT_DIR) && strlen(de->d_name) > 0 && de->d_name[0] != '.') {
                string p(de->d_name);
                if(de->d_type == DT_REG) fileList->push_back(base+'/'+p);
                if(de->d_type == DT_DIR) bfs.push(base+'/'+p);
            }
        }
        bfs.pop();
        closedir(dir);
    }
    return fileList;
}

vector<tuples *> *getindex(char *indexfile)
{   
    vector<tuples *> *vtuples = new vector<tuples *>;
    char* ifile = indexfile;
    char urlBuff[4096];

    while((*ifile) != 0) {
        tuples *indextuple = new tuples;
        int i = 0;

        //url
        while((*ifile)!=' ') {
            urlBuff[i] = (*ifile);
            i++;
            ifile++;
        }
        urlBuff[i] = 0;
        indextuple->url = urlBuff;
        while((*ifile) == ' ') ifile++;
        
        //depth
        indextuple->depth = atoi(ifile);
        while((*ifile) != ' ') ifile++;
        while((*ifile) == ' ') ifile++;
        
        //unknow
        indextuple->unknown = atoi(ifile);
        while((*ifile) != ' ')  ifile++;
        while((*ifile) == ' ')  ifile++;
        
        //length
        indextuple->length = atoi(ifile);
        while((*ifile) != ' ') ifile++;
        while((*ifile) == ' ') ifile++;
        
        //ip address
        i=0;
        while((*ifile)!=' ') {
        	indextuple->IP[i] = (*ifile);
            i++;
            ifile++;
        }
        indextuple->IP[i] = 0;
        while((*ifile) == ' ')  ifile++;
        
        //port
        indextuple->port = atoi(ifile);
        while((*ifile) != ' ')  ifile++;
        while((*ifile) == ' ')  ifile++;
        
        //status
        i=0;
        while((*ifile)!=' ' && (*ifile) != '\n'&& (*ifile) != 0) {
        	indextuple->status[i] = (*ifile);
            i++;
            ifile++;
        }
        indextuple->status[i] = '\0';

        vtuples->push_back(indextuple);
        while((*ifile) != '\n' && (*ifile) != 0) ifile++;
        if((*ifile) == 0) break;
        else ifile++;
    }
    return vtuples;
}

vector<char*> *getpage(char* datafile, vector<tuples *>* vtuples)
{
    vector<char*> *pages = new vector<char*>();
    char *data = datafile;

    for(int i=0;i<vtuples->size();i++) {
        tuples *ituple = (*vtuples)[i];
        int pageLength= ituple->length;
        if (pageLength < 0 || pageLength > MAX_PAGE_LENGTH) {
            cout<<"Page length is incorrect, skip the whole file:"<<pageLength<<endl;
            cout<<ituple->url<<endl;
            return pages;
        }
        if(strcmp(ituple->status, "ok") != 0) cout<<"status is not ok"<<endl;
        else {
            int pageLength= ituple->length;
            char *page = new char[pageLength+1];
            strncpy(page, data, pageLength);
            page[pageLength] = '\0';
            pages->push_back(page);
        }
        data += pageLength;
    }
    return pages;
}

