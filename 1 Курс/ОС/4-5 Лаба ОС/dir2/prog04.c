#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
int fd, result; 
size_t size; 
char resstring[14]; 
char name[]="aaa.fifo";

(void)umask(0);
mknod(name, S_IFIFO | 0666, 0); 
result =fork();
if (result > 0) {
fd=open(name, O_WRONLY);
size = write(fd, "Hello, world!", 14);

close(fd);
printf("Parent exit\n");}
else {
fd=open(name, O_RDONLY);

size = read(fd, resstring, 14);

printf("%s\n ", resstring);

close(fd);
}
return 0;
}
