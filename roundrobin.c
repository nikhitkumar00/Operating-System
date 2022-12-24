#include <stdio.h>

void main()
{
	int numberofprocess,timesplice;
	int bt[10],ct[10],wt[10],tat[10];
	int done[10],tbt[10];
	float ttat=0,twt=0;

	printf("\nEnter the number of processes:\n");
	scanf("%d",&numberofprocess);

	printf("Enter the Burst time of each process in order:\n");
	for(int i=0;i<numberofprocess;i++)
	{
		scanf("%d",&bt[i]);
		tbt[i] = bt[i];
	}

	printf("Enter the Time Quantum:\n");
	scanf("%d",&timesplice);

	int temptime = 0;
	printf("\nPROCESS     BURST TIME     TURNAROUND TIME     WAITING TIME\n");
	for(int j=0;j<numberofprocess;j++)
	{
		for(int i=0;i<numberofprocess;i++)
		{
			if(done[i]!=1)
			{
				if(tbt[i] <= timesplice)
				{
					done[i] = 1;
					ct[i] = temptime + tbt[i];
					temptime = temptime + tbt[i];
					tat[i] = ct[i];
					wt[i] = tat[i] - bt[i];
					printf("P[%d]          %d             %d                   %d\n",i,bt[i],tat[i],wt[i]);
				}

				else
				{
					tbt[i] = tbt[i] - timesplice;
					temptime = temptime + timesplice;
				}
			}
		}
	}

	for(int i=0;i<numberofprocess;i++)
    {
        ttat = ttat + tat[i];
        twt = twt + wt[i];
    }

    printf("\nAverage Turnaround Time: %f\n",ttat/numberofprocess);
    printf("\nAverage Waiting Time: %f\n",twt/numberofprocess);
}