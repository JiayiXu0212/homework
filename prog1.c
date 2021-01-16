#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	location1:
	printf("Code at: %p\n", &&location1);
	printf("PID: %d\n", getpid());
	
	// Wait until user types a character and press Enter
	fgetc(stdin);
	return 0;
}
