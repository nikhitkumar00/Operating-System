#include<stdio.h>

int numberofsearch,framesize;
int list[15],frame[10],frequency[100];
int fault=0,index=10;

void main()
{
	printf("\nEnter the number of search sequence:\n");
	scanf("%d",&numberofsearch);

	printf("Enter the sequence in series:\n");
	for(int i=0;i<numberofsearch;i++)
	{
		scanf("%d",&list[i]);
	}

	printf("Enter the size of frame;\n");
	scanf("%d",&framesize);

	for(int i=0;i<framesize;i++)
	{
		frame[i]=-1;
	}

	for(int i=0;i<100;i++)
	{
		frequency[i]= -1;
	}

	for(int i=0;i<numberofsearch;i++)
	{
		int flag = 0;
		for(int k=0;k<framesize;k++)
		{
			if(frame[k] == list[i])
			{
				flag=1;
			}
		}
		
		if(flag ==1)
		{
			frequency[list[i]]++;
		}
		else
		{
			frequency[list[i]]++;
			int small = 100;
			for(int l=0;l<framesize;l++)
			{
				if(small > frequency[frame[l]])
				{
					small = frequency[frame[l]];
					index = l;
				}
			}

			frame[index] = list[i];
			fault++;
		}

		for(int j=0;j<framesize;j++)
		{
			printf("%d    ",frame[j]);
		}
		printf("Page Fault: %d\n",fault);
	}
}