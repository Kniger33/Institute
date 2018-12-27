#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main ()
{ 
	int fd, result;
	size_t size;
	char resstring[14];
	char name [] = "aaa.fifo";
	(void)umask(0);	
	fd = open(name, O_RDONLY);
	size = read(fd, resstring, 14);
	printf("%s\n", resstring);
	close(fd);
	printf("Exit");
	return 0;
}
