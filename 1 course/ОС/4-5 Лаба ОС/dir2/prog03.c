#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{ 
	int fd[2], n=0, res;
	size_t size;
	res=pipe(fd);
	while (res != -1)
	{
		res=pipe(fd);
		n=n+1;
	}
	printf ("%d\n", n);
	return 0;
}

