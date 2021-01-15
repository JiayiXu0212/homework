// Name: Jiayi Xu
// Class: CS 360
// Project: Assignment 1
// Due Day: Jan 15 2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {
	for (int i =2; i< argc; i++){
		// open target file and initialize the buffer with size 1000 to store the string
		FILE *fp = fopen( argv[i], "r" );   
		char buffer[1000];
		
		// if no search term and no file specified, will show the format to tell the user how to use it
		// ex: ./bcgrep
		if (argc==1) {
			printf("./bcgrep [OPTION]... PATTERNS [FILE]...\n");
			exit(1);
		}
		
		// if is uncorrect file name or null, will be printed out cannot open
		// ex: ./bcgrep Bellevue text.txt
		if( fp == NULL && argc>=3) {
			printf( "bcgrep: cannot open file\n");
			exit(1);
		}
		
		// if missing search term or the file name, will print out the correct format for user
		// ex: ./bcgrep test.txt
		if( strstr(argv[1],".")!=NULL && argc < 3) {
			printf( "bcgrep: searchterm [file...]\n");
			exit(1);
		}
		
		// if a search term, but no file, is specified, read from standard input
		// ./bcgrep BellevueCollege    --> will print out "BellevueCollege"
		if ((strstr(argv[1],".")==NULL) && argc<3){
			printf("%s\n",argv[1]);
			exit(1);
		}
		
		
		
		// read file as long as the line is not null, if the line has the word match the searchterm, will print out that line, otherwise, will return 0.  " Case Sensitive"
		// ex: ./bcgrep Bellevue test.txt
		while( fgets(buffer, 1000, fp) != NULL) {
			if (strstr(buffer,argv[1]) ){
				fputs(buffer,stdout);
			}
		}
		fclose(fp);
	}
	return 0;
}
