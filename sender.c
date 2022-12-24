#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{
	void *shared_memory;
	char buffer[100];

	int shmid = shmget((key_t)1111,1024,0666|IPC_CREAT);
	shared_memory = shmat(shmid,NULL,0);

	printf("Shared memory created with id: %d \n",shmid);
	printf("Enter something to write into the shared memory\n");
	read(0,buffer,100);
	strcpy(shared_memory,buffer);
}