#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main ()
{
	pid_t pid, ppid;
	int a=0;
	fork();
	while (a<5) 
	{
		pid=getpid();
		ppid=getppid();
		a++;
		printf ("pid=%d\n, ppid=%d\n, result=%d\n", (int)pid, (int)ppid, a);
	}
	return 0;
}
