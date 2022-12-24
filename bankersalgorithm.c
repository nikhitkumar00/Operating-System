#include <stdio.h>

void main()
{
    int numberofresources,numberofrows;
    int allocated[10][5],maximum[10][5],available[5],need[10][5];
    int flag,done[10];

    printf("\nEnter the number of resources:\n");
    scanf("%d",&numberofresources);

    printf("Enter the number of rows that you wish to enter:\n");
    scanf("%d",&numberofrows);

    printf("Enter the allocated matrix in order:\n");
    for(int i=0;i<numberofrows;i++)
    {
        done[i]=0;
        for(int j=0;j<numberofresources;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }

    printf("Enter the maximum matrix in order:\n");
    for(int i=0;i<numberofrows;i++)
    {
        for(int j=0;j<numberofresources;j++)
        {
            scanf("%d",&maximum[i][j]);
        }
    }

    printf("Enter the available matrix:\n");
    for(int i=0;i<numberofresources;i++)
    {
        scanf("%d",&available[i]);
    }

    printf("\n\nNeed Matrix:\n");
    for(int i=0;i<numberofrows;i++)
    {
        for(int j=0;j<numberofresources;j++)
        {
            need[i][j]=maximum[i][j]-allocated[i][j];
            printf("%d  ",need[i][j]);
        }
        printf("\n");
    }


    for(int l=0;l<numberofrows;l++)
    {
        for(int i=0;i<numberofrows;i++)
        {
            flag=0;
            if(done[i]==0)
            {
                for(int j=0;j<numberofresources;j++)
                {
                    if(need[i][j] <= available[j])
                    {
                        flag++;
                    }
                }
                if(flag==numberofresources)
                {
                    printf("Process P[%d] completed\n",i);
                    for(int k=0;k<numberofresources;k++)
                    {
                        available[k] = available[k] + allocated[i][k];
                    }
                    done[i]=1;
                }
            }
        }
    }
    

    for(int i=0;i<numberofrows;i++)
    {
        if(done[i]==0)
        {
            printf("Deadlock occured at P[%d]\n",i);
        }
    }
}