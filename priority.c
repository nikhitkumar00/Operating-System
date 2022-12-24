#include <stdio.h>

void main()
{
    int numberofprocess;
    int bt[10],ct[10],nm[10],priority[10];
    int tat[10],wt[10];
    float ttat = 0,twt = 0;

    printf("\nEnter the number of processes that you need to enter:\n");
    scanf("%d",&numberofprocess);

    printf("Enter the burst time of each process in order:\n");
    for(int i=0;i<numberofprocess;i++)
    {
        scanf("%d",&bt[i]);
		nm[i]=i;
    }

	printf("Enter the priority of each process in order:\n");
    for(int i=0;i<numberofprocess;i++)
    {
        scanf("%d",&priority[i]);
    }

	for(int i=0;i<numberofprocess-1;i++)
	{
		for (int j=0;j<numberofprocess-i-1;j++)
		{
			if(priority[j] > priority[j+1])
			{
				int temp = nm[j];
				nm[j] = nm[j+1];
				nm[j+1] = temp;

				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;

				temp = priority[j];
				priority[j] = priority[j+1];
				priority[j+1] = temp;
			}
		}
	}

    ct[-1]=0;
    for(int i=0;i<numberofprocess;i++)
    {
        ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i];
        wt[i] = ct[i] - bt[i];
    }

    printf("\nPROCESS NO.   BURST TIME   PRIORITY      TURNAROUND TIME   WAITING TIME\n");
    for(int i=0;i<numberofprocess;i++)
    {
        printf("P[%d]           %d           %d           %d               %d\n",nm[i],bt[i],priority[i],tat[i],wt[i]);
    }


    for(int i=0;i<numberofprocess;i++)
    {
        ttat = ttat + tat[i];
        twt = twt + wt[i];
    }

    printf("\nAverage Turnaround Time: %f\n",ttat/numberofprocess);
    printf("\nAverage Waiting Time: %f\n",twt/numberofprocess);
}