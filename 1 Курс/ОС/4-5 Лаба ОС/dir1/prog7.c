#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[], char *envp[])
{
	(void)execl ("/bin/cat", "cat", "l.c", (char *)NULL);
	printf  ("Error\n");
	exit(-1);
	return 0;
}
