#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h> 
#include <string.h>
#include <stdio.h>

/*
0-mutex;
1-empty;
2-full;
*/

int semid;
struct sembuf sem[3];

int msgqid;
struct msg
{ 
	long mtype;
    char mtext[10]; 
} myMsg;

int set_semvalue() 
{
	sem[0].sem_num = 0;
    sem[0].sem_op = 1;
	sem[0].sem_flg = SEM_UNDO;

    sem[1].sem_num = 1;
    sem[1].sem_op = 5;
    sem[1].sem_flg = SEM_UNDO;
    
	sem[2].sem_num = 2;
    sem[2].sem_op = 0;
    sem[2].sem_flg = SEM_UNDO;

	semop(semid, sem, 3);

	return 0;
}

int semaphore_p(int semNum) 
{
	sem[semNum].sem_num = semNum;
	sem[semNum].sem_op = -1; // P();
	sem[semNum].sem_flg = SEM_UNDO;

	semop(semid, sem, 3);

	return 0;	
}

int semaphore_v(int semNum) 
{
	sem[semNum].sem_num = semNum;
	sem[semNum].sem_op = 1; // V();
	sem[semNum].sem_flg = SEM_UNDO;

	semop(semid, sem, 3);

	return 0;	
}

int main() 
{
	key_t msgKey = 14;
	key_t key = 28;

	semid = semget(key, 3, 0666 | IPC_CREAT);

	msgqid = msgget(msgKey, 0666 | IPC_CREAT);

	set_semvalue();

	while(1)
	{

		semaphore_p(2);
		semaphore_p(0);
		
		printf("Get item\n");
		msgrcv(msgqid, (struct msg *) &myMsg, 10, 0, 0);
		
		semaphore_v(0);
		semaphore_v(1);

		printf("Consume item\n");
		printf("%s\n", myMsg.mtext);

	}

	return 0;
}

