#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[], char *envp[])
{
	int p=fork();
	if (p==-1) 
	{
		printf ("ERROR");
		exit(-1);
	} else if (p==0)
	{
		printf ("chield process:\n");
		(void)execl ("/bin/cat", "cat", "hello.c",(char *)NULL);
	} else
	{
		printf ("parent process:\n");
	}
	return 0;
}
		
