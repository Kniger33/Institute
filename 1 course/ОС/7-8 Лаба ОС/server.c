#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int semid;
struct sembuf sem[1];
union semun { 
	int val; 
	struct semid_ds *buf; 
	unsigned short *array; 
} sem_union;

int set_semvalue() 
{
	sem[0].sem_num = 0;
    sem[0].sem_op = -1;
	sem[0].sem_flg = SEM_UNDO;

	semop(semid, sem, 1);

	return 0;
}

int semaphore_p(int semNum) 
{
	sem[semNum].sem_num = semNum;
	sem[semNum].sem_op = -1; // P();
	sem[semNum].sem_flg = SEM_UNDO;

	semop(semid, sem, 1);

	return 0;	
}

int semaphore_v(int semNum) 
{
	sem[semNum].sem_num = semNum;
	sem[semNum].sem_op = 1; // V();
	sem[semNum].sem_flg = SEM_UNDO;

	semop(semid, sem, 1);

	return 0;	
}

int main()
{
    char* string;
    char estr[50];
    int* mas;
    
    FILE *file;
    
    key_t keysem = 283;
    key_t keystr = 383;
    key_t keymas = 183;
    
    semid = semget(keysem, 1, 0666 | IPC_CREAT);
    int shmidStr = shmget (keystr, 50 * sizeof(char), 0666 | IPC_CREAT);
    int shmidMas;
    
    if((shmidMas = shmget(keymas, 1 * sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0)
    {
    	printf("Memory already used!\n");
        exit(-1);
    }
    
    string = (char*)shmat(shmidStr, NULL, 0);
    mas = (int*)shmat(shmidMas, NULL, 0);

    set_semvalue(); 

    int i = 0, j = 1;
    while(i < 10)
    {
        file = fopen("File", "r");
        for(j = 0; j < mas[0]; j++)
        {
        	fgets (estr, 50, file);
        }
        fclose(file);
        
        for(j = 0; j < strlen(estr); j++)
        {
        	string[j] = estr[j];
        }
        
        string[strlen(estr)] = '\0';
        
 		printf("Number of string: %d\n", mas[0]);
        printf("String: %s\n", string);

        i++;
        semaphore_p(0);
    }
    
    shmdt(mas);
    shmdt(string);

    semctl(semid, 0, IPC_RMID, sem_union);
    shmctl(shmidStr, IPC_RMID, NULL);
    shmctl(shmidMas, IPC_RMID, NULL);
    return 0;
}
