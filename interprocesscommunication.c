#include <stdio.h>
#include <stdlib.h>
#define buffersize 5

int buffer[5],in=0,out=0,count=1;

void print()
{
	for(int i=0;i<buffersize;i++)
	{
		printf("%d   ",buffer[i]);
	}
}

void producer()
{
	if((in+1)%buffersize == out)
	{
		printf("Buffer is full\n");
	}
	else
	{
		int produced = count;
		count++;
		buffer[in] = produced;
		in = (in+1)%buffersize;
		printf("[%d] Produced\n",produced);
	}
	print();
}

void consumer()
{
	if(in == out)
	{
		printf("Buffer is empty\n");
	}
	else
	{
		int consumed;
		consumed = buffer[out];
		out = (out+1)%buffersize;
		printf("[%d] Consumed\n",consumed);
	}
	print();
}

void main()
{
	int choice;
	while(1)
	{
		printf("\nEnter the choice:\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				producer();
				break;

			case 2:
				consumer();
				break;

			default:
				exit(0);
				break;
		}
	}
}