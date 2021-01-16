#include  <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("Process ID: %d\n", getpid());
	
	// Read the next character from stdin (used as a simple trick to keep the process form exiting)
	fgetc(stdin);
	return 0;
}
