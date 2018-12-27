#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main ()
{
	pid_t pid, ppid, p;
	int a=0;
	(void)fork();
	while (a<5) 
	{
		p=fork();
		if (p==-1) {printf ("ERROR");}
		else if (p==0)
		{
			printf ("chield process: ");
			a=a+2;
		} else
		{
			printf ("parent process: ");
			a=a+1;
		}
		pid=getpid();
		ppid=getppid();
		
		printf ("pid=%d\n, ppid=%d\n, result=%d\n", (int)pid, (int)ppid, a);
	}
	return 0;
}
