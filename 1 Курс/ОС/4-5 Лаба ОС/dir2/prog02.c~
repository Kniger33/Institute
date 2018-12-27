#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{ 
	int fd[2], fd1[2], result;
	size_t size;
	char resstring [14], resstring1[15];
	pipe(fd);
	pipe(fd1);
	
	if ((pipe(fd)<0) || (pipe(fd1)<0))
	{
		printf ("error:no pipe\n");
		exit (-1);
	}
	result=fork();
	if (result=-1)
	{
		printf ("error:no chield\n");
		exit (-1);
	} else if (result>0)
	{
		close (fd[0]);
		size = write (fd[1], "Hello, world!", 14);
		if (size != 14)
		{
			printf ("error\n");
			exit (-1);
		}
		size = read(fd1[0], resstring1, 15);
		printf ("%s\n", resstring1);
		close (fd[1]);
		close(fd1[0]);
		printf ("parent exit\n");	
	} else 
	{
		close(fd[1]);
		size = read(fd[0], resstring1, 15);
		if (size < 0)
		{
			printf ("error\n");
			exit (-1);
		}
		printf ("%s\n", resstring1);
		close (fd[0]);
		size = write (fd1[1], "Hello, planet!", 15);
		printf ("chield exit\n");
		close (fd1[1]);
	}
	return 0;
}
