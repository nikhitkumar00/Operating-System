#include <stdio.h>

void main()
{
    int numberofprocess;
    int bt[10],ct[10];
    int tat[10],wt[10];
    float ttat = 0,twt = 0;

    printf("\nEnter the number of processes that you need to enter:\n");
    scanf("%d",&numberofprocess);

    printf("Enter the burst time of each process in order:\n");
    for(int i=0;i<numberofprocess;i++)
    {
        scanf("%d",&bt[i]);
    }

    ct[-1]=0;
    for(int i=0;i<numberofprocess;i++)
    {
        ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i];
        wt[i] = ct[i] - bt[i];
    }

    printf("\nPROCESS NO.   BURST TIME   TURNAROUND TIME   WAITING TIME\n");
    for(int i=0;i<numberofprocess;i++)
    {
        printf("P[%d]           %d           %d               %d\n",i,bt[i],tat[i],wt[i]);
    }

    for(int i=0;i<numberofprocess;i++)
    {
        ttat = ttat + tat[i];
        twt = twt + wt[i];
    }

    printf("\nAverage Turnaround Time: %f\n",ttat/numberofprocess);
    printf("\nAverage Waiting Time: %f\n",twt/numberofprocess);
}