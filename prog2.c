#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

char global[] = "This is a global string";
const int read_only_int = 100;
int main(){
	 int pid = getpid();
	 foo:
	 	printf("Process id: %d\n",pid);
	 	printf("global string: %p\n", &global);
	 	printf("read_only_integer: %p\n", &read_only_int);
	 	printf("the code:: %p\n", &&foo);
	 	
	 	printf("\n/proc/%d/maps \n\n", pid);
	 	char command[50];
	 	sprintf(command,"cat /proc/%d/maps", pid);
	 	
	 	// We are telling the system function to execute this command (as if typing it on the command line)
	 	system(command);
	 	return 0;
}
