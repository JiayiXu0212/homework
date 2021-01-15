#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	// for loop for read more than one files
 	for (int i =1; i< argc; i++){
		FILE *fp=fopen(argv[i],"r");  
		char buffer[1000];
		
		// if no files specified, just exit and return 0
		// ex: ./bccat
		if ( argv[i] == 0 ){
			exit(1);
		}
		
		// try to open files and fails, print "wcat: cannot open file" and exit 1
		if (fp == NULL ) {
			printf("bccat: cannot open file\n");
			exit(1);
		}
		
		// read specified files, and print 
		while (fgets(buffer,1000,fp)!=NULL) {
			
			printf("%s",buffer);
		}
		fclose(fp);
		
		// to separate files, and make commond easy to read
		printf("=========================================================================================\n");
	}
	return 0;
}
