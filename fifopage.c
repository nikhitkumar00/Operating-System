#include<stdio.h>
int numberofpage,numberofframe,frame[10],list[20],pointer=0,found,fault;

void initialise()
{
    for(int i=0;i<numberofframe;i++)
    {
        frame[i]=-1;
    }
}

int check(int a)
{
    int flag=0;
    for(int i=0;i<numberofframe;i++)
    {
        if(a==frame[i])
        {
            flag=1;
        }
    }
    return flag;
}

void print(int a)
{
    printf("\n");
    for(int i=0;i<numberofframe;i++)
    {
        printf("%d ",frame[i]);
    }
    printf("    Fault: %d   ",fault);

    if(a==0)
    {
        printf("Page Miss\n");
    }
    else
    {
        printf("Page Hit\n");
    }
}

void replace(int a)
{
    frame[pointer]=a;
    pointer = (pointer+1)%numberofframe;
}

void main()
{
    printf("\nEnter the number of search sequence that you wish to enter:\n");
    scanf("%d",&numberofpage);

    printf("\nEnter the pages in order of execution:\n");
    for(int i=0;i<numberofpage;i++)
    {
        scanf("%d",&list[i]);
    }

    printf("\nEnter the number of frames:\n");
    scanf("%d",&numberofframe);

    initialise();

    for(int i=0;i<numberofpage;i++)
    {
        found = check(list[i]);

        if(found==0)
        {
            fault++;
            replace(list[i]);
            print(found);
        }
        else
        {
            print(found);
        }
    }
}