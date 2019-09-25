#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	pid_t pid, p;
	p=fork();
	if (p==0) 
	{
		pid=getpid();
		printf (printf ("pid=%d\n", (int)pid);
		exit (0);
	}
	sleep(60);
	return 0;
}
