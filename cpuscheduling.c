#include <stdio.h>
#include <stdlib.h>
int partitioncount,partition[10],flag[10],inputcount,input[10],flagg[10],choice;

void firstfit()
{
    for(int i=0;i<partitioncount;i++)
    {
        for(int j=0;j<inputcount;j++)
        {
            if(flag[i]==0 && flagg[j]==0)
            {
                if(input[j]<partition[i])
                {
                    flag[i]=1;
                    flagg[j]=1;
                    printf("[%d]input allocated in partition space of %d\n",input[j],partition[i]);
                }
            }
        }
    }
}

void bestfit()
{
    for(int i=0;i<partitioncount-1;i++)
    {
        for(int j=0;j<partitioncount-i-1;j++)
        {
            if(partition[j]>partition[j+1])
            {
                int temp=partition[j];
                partition[j]=partition[j+1];
                partition[j+1]=temp;
            }
        }
    }

    for(int i=0;i<partitioncount;i++)
    {
        for(int j=0;j<inputcount;j++)
        {
            if(flag[i]==0 && flagg[j]==0)
            {
                if(input[j]<partition[i])
                {
                    flag[i]=1;
                    flagg[j]=1;
                    printf("[%d]input allocated in partition space of %d\n",input[j],partition[i]);
                }
            }
        }
    }
}

void worstfit()
{
    for(int i=0;i<partitioncount-1;i++)
    {
        for(int j=0;j<partitioncount-i-1;j++)
        {
            if(partition[j]<partition[j+1])
            {
                int temp=partition[j];
                partition[j]=partition[j+1];
                partition[j+1]=temp;
            }
        }
    }

    for(int i=0;i<partitioncount;i++)
    {
        for(int j=0;j<inputcount;j++)
        {
            if(flag[i]==0 && flagg[j]==0)
            {
                if(input[j]<partition[i])
                {
                    flag[i]=1;
                    flagg[j]=1;
                    printf("[%d]input allocated in partition space of %d\n",input[j],partition[i]);
                }
            }
        }
    }
}

void main()
{
    printf("Enter the number of partiton spaces: ");
    scanf("%d",&partitioncount);

    for(int i=0; i<partitioncount; i++)
    {
        printf("Enter the %dth partition count space: ",i+1);
        scanf("%d",&partition[i]);
        flag[i]=0;
    }

    printf("Enter the number of input questions: ");
    scanf("%d",&inputcount);

    for(int i=0; i<inputcount; i++)
    {
        printf("Enter the input string: ");
        scanf("%d",&input[i]);
        flagg[i]=0;
    }

    printf("Enter thr choice that you wish to do\n1: Firstfit\n2: Bestfit\n3: Worstfit");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        firstfit();
        break;

    case 2:
        bestfit();
        break;

    case 3:
        worstfit();
        break;
    
    default:
        exit(0);
        break;
    }

    for(int i=0;i<inputcount;i++)
    {
        if(flagg[i]==0)
        {
            printf("Compaction is required");
            break;
        }
    }
}