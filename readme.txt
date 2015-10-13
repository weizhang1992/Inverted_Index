Assignment 2 of WSE homework
Name:Wei Zhang 

Introduction
I use c/c++ to write the program. Below is three mainly result files. DoctoUrl table. Lexicon table. Inverted index file.

DoctoUrl table:
ASCII: URL, DocID, fileID, pointer,WordCount
  BIN: lenofURL,URL, DocID, fileID, pointer,WordCount
- fileID: which data file contains this url and Doc
- pointer: points to the doc in the data file with fileID
WordCount: Count the number of words in doc

Lexicon table:
ASCII:Word, NumofDoc, fileID, Pointer, sizeoflist
  BIN:Lenofword, Word, NumofDoc, fileID, Pointer, sizeoflist
- NumofDoc: number of docs that containing this word
- fileID: which inverted index file contains this list
invertedPointer: points to the inverted index list
- sizeoflist: size of the list belong to this word

Inverted Index file:
docID, Freq, pos, docID, Freq, pos,………
BIN: compressed by Vbyte
- docID: compressed by the difference of two docID
- Freq: the number the specific words in this doc
pos: first word’s position in the doc

Configuration:
#define FILEMODE //you can choose BIN to output, ASCII to debug
#define MAX_item_per_tempindex 10000000 //max items in temp index file 
#define Maxfinalindexsize 2*1000*1000*1000 //max size of final file
#define Datafilepath //data source file path
#define Tempmergedindex //merged temp index file
#define Lexicon_filepath //lexicon file
#define Url_Doc_filepath //doc_url file
#define Finalfilepath //file inverted index file 
#define Tempindexpath //temp index files 

How to run

This program is write in eclipse with CDT. Please use eclipse with CDT to compile it and run it.

Source folder Structure

|-- data    // store temp index and merge index and 3 final file
|-- Debug   // Eclipse debug file
|-- nz_full // this data contains until vol-699. larger than nz10
|-- nz2     // this data contains until vol-87, used as test data
|-- src     // contain all source file

What this program can do

Steps of Generating Inverted Index

use getfilelist to get all the file path recursively
use gzip.cpp to read the gzipped data file and index file
3. use provided parser to parse each page to get tuples.
4. sort and write the tuples to a file when the number of tuples           
   more than MAX_item_per_tempindex
5. then we have tempindex files in text files for unix sort
6. write the doc_url table.
7. use unix sort to merge all the sorted tempindex files
8. read merged index file to final inverted index file by 
   compress the docID and vbyte compress. stored as binary file.
9. write the lexicon table.

Major modules

Config:      set the max final file size, and so on.
vbyte.h:     compress the final inverted index file
Parser:      provided in course page. parse data,index file
gzip:    	   provided in course page. read gzipped file.
getfilelist: recursively get file path from one folder
table:       set lexicon,doc_url,inverted_index,rawpost format
tempindex:   method to generate temp index file
invertindex: method to generate file inverted index file
main:        main function

How long it takes

Use the nz data as the program data set. This data contains until vol-699, which is larger than nz10. 

Size of nz2 data file: 132MB
Cost time of run program of nz2: 117 seconds
- Cost time of generate temp index files: 96 Seconds.
- Cost time of merge the temp index file: 4 Seconds.
- Cost time of generate final index file: 15 Seconds.

Size of nz  data file: 1.5GB
Cost time of run program of nz: 1745 Seconds.
- Cost time of generate temp index files: 1394 Seconds.
- Cost time of merge the temp index file: 132  Seconds.
Cost time of generate final index file: 219  Seconds.

How large the final file

Size of invert  index: 873.8MB
Size of lexicon table:  36.5MB
Size of doc_url table: 167.7MB

Limitation

The maximum of size of each file inverted index file is 4GBytes

