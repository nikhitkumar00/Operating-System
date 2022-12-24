#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main()
{
	void *shared_memory;
	int shmid = shmget((key_t)1111,1024,0666);
	shared_memory = shmat(shmid,NULL,0);
	printf("Connected to id: %d \n",shmid);
	printf("Data in shared memory: %s",(char *)shared_memory);
}