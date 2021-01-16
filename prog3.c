#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main() {
	int x = 10;
	double y = 100.0;
	int pid=getpid();
	printf("Process id: %d\n",pid);
	printf("integer: %p\n", &x);
	printf("double: %p\n", &y);
	printf("\n/proc/%d/maps \n\n",pid);
	char command[50];
	sprintf(command,"cat /proc/%d/maps", pid);
	system(command);
	return 0;
}
