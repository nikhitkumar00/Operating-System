#include <stdio.h>
#include <stdlib.h>
int buffersize,choice;
int mutex,full,empty;

void producer()
{
    if(full == buffersize)
    {
        printf("\nBuffer is full\nWait for Consumer to consume\n\n");
    }
    else
    {
        mutex--;
        full++;
        empty--;
        printf("\nProducer has produced an item and stored in the buffer\n\n");
        mutex++;
    }
}

void consumer()
{
    if(full==0)
    {
        printf("\nBuffer is empty\nWait for Producer to produce\n\n");
    }
    else
    {
        mutex--;
        full--;
        empty++;
        printf("\nConsumer has consumed an item that is stored in the buffer\n\n");
        mutex++;
    }
}

void main()
{
    printf("\nEnter the size of the buffer: ");
    scanf("%d",&buffersize);

    full=0;
    empty=buffersize;
    mutex=0;

    while(1)
    {
        printf("Enter your choice: \n1: Producer\n2: Consumer\n3: Exit\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                if(mutex==0)
                {
                    producer();
                }
                break;

            case 2:
                if(mutex==0)
                {
                    consumer();
                    break;
                }
                break;

            default:
                exit(0);
        }
    }
}
