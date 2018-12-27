#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main()
{
	union semun { 
		int val; 
		struct semid_ds *buf; 
		unsigned short *array; 
	} sem_union; 
	
	key_t key = 28;
	int semid = semget(key, 3, 0666 | IPC_CREAT);

	semctl(semid, 0, IPC_RMID, sem_union);
	semctl(semid, 1, IPC_RMID, sem_union);
	semctl(semid, 2, IPC_RMID, sem_union);

	return 0;
}
