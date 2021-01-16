#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main() {
	int *a=malloc(sizeof(int));
	double *b=malloc(sizeof(double));
	float *c=malloc(sizeof(float));
	int pid=getpid();
	printf("Process id: %d\n",pid);
	printf("a pointing to: %p\n", a);
	printf("b pointing to: %p\n", b);
	printf("c pointing to: %p\n", c);
	printf("\n/proc/%d/maps \n\n",pid);
	char command[50];
	sprintf(command,"cat /proc/%d/maps", pid);
	system(command);
	return 0;
}
