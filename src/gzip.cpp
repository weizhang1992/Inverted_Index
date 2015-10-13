#include "gzip.h"
#include "stdlib.h"
#include "Config.h"
#include  <zlib.h>
#include <iostream>

char *ReadGZFile(const char *filePath)
{
    gzFile gzfile = gzopen(filePath, "r");
    int size = 409600;//50kb
    char *buffer=(char *)malloc(size);
    int oldSize=size;

    int count=0;             //The number of bytes that already read
    while (!gzeof(gzfile))
    {
        count+=gzread(gzfile,buffer+count,oldSize);
        if (count==size)                    // Reallocate when buffer is full
        {
            oldSize=size;
            size*=2;
            if (size > 536870912*2) {
                std::cout<<"gzip file incorrect:"<<size<<std::endl;
                gzclose(gzfile);
                free(buffer);
                return NULL;
            }

            buffer=(char *)realloc(buffer,size);
        }
    }
    buffer[count] = '\0';
    gzclose(gzfile);
    return buffer;

}
