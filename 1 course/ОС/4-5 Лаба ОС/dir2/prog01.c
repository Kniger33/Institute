#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{ 
	int fd[2], result;
	size_t size;
	char resstring [14];
	pipe(fd);
	
	if (pipe(fd)<0)
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
		close (fd[1]);
		printf ("parent exit\n");
		(void)execl ("/bin/echo", "echo", "message1", (char *)NULL);		
	} else 
	{
		close(fd[1]);
		size = read(fd[0], resstring, 14);
		if (size < 0)
		{
			printf ("error\n");
			exit (-1);
		}
		printf ("%s\n", resstring);
		close (fd[0]);
		printf ("chield exit\n");
		(void)execl ("/bin/echo", "echo", "message2", (char *)NULL);	
	}
	return 0;
}
