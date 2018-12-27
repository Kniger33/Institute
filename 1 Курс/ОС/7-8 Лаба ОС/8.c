#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

static void handler(int signum)
{
        printf("Signal function trigged with signum: %i\n", signum);
}

int main(int argc, char *argv[])
{
  pid_t pid1, pid2;
  int fd1[2],fd2[2];
  if (pipe(fd1) != 0 || pipe(fd2) != 0)  //Создаем каналы
  {
        printf("Не работает.\n");
        exit(1);
  }
  printf("Pipes created.\n");
  switch(pid1 = fork())
  {
  case -1: 
        printf("Process 1:ERROR create\n");
        exit(1);
  break;
  case 0: 
        //process1
        printf("Process 1: Created\n");
        signal(SIGUSR1, handler);
        printf("Process 1: write data to pipe1, go to Process 2\n");
        write(fd1[1], "process 0 test string\n", 23);
        printf("Process 1: waiting for signal.\n");
        pause();
        printf("Process 1: reached on signal.\n");
        char recieve[255];
        char buffer[255];  
        read(fd2[0], recieve, 255);
        read(fd1[0], buffer, 255);
        strcat(recieve, buffer);
        strcat(recieve, "process 1 test string\n");
        printf("Process 1: read data from pipe2, send data to pipe1, terminate.\n");
        write(fd1[1], recieve, strlen(recieve));
        exit(0);
  break;
  default:
  switch(pid2 = fork()){
  case -1:
        printf("Process 2:ERROR create\n");
        exit(1);
  break;
  case 0:
        //process 2
        printf("Process 2: Created\n");
        write(fd2[1], "process 2 test string\n",23);
        printf("Process 2: write data to pipe2, sending signal to Process 1\n");
        kill(pid1, SIGUSR1);
        exit(0);
  break;
  default:
        wait(NULL);/*Ждем пока оба процеса обнулятся*/
        wait(NULL);
        char output[255];
        read(fd1[0], output, 255);
        printf("Result pid1: %s\n", output);
  }
  }
  exit(0);
}