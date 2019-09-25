#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

union semun 
{
	int val; 
	struct semid_ds *buf; 
	unsigned short *array;
}arg;

int main () 
{
	int semid, shmid, a;
	fork();	

	key_t keysem = 1012;
	key_t keymem = 2007;

	semid = semget (keysem, 3, IPC_CREAT);
	
	shmid = shmget (keymem, 10, IPC_CREAT);

	arg.val = 5;

	semctl(semid, 0, SETVAL, arg);
	a = semctl(semid, 0, GETVAL, arg);

	sleep(40);
	
	printf("%d\n", arg.val);
	printf("%d", a);

	return 0;
}
