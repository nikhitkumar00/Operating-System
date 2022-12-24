#include <stdio.h>

	int search[15],frame[10],priority[10];
	int numberofsearch,framesize,location;
	int fault=0,count=1;

int searchframe(int a)
{
	int flag=0;
	for(int i=0;i<framesize;i++)
	{
		if(frame[i]==a)
		{
			flag=1;
			location=i;
		}
	}
	return flag;
}

int position()
{
	int small=100,index;
	for(int i=0;i<framesize;i++)
	{
		if(priority[i]<small)
		{
			small = priority[i];
			index = i;
		}
	}
	return index;
}

void main()
{
	printf("\nEnter the number of search sequence:\n");
	scanf("%d",&numberofsearch);

	printf("Enter the search sequence in order\n");
	for(int i=0;i<numberofsearch;i++)
	{
		scanf("%d",&search[i]);
	}

	printf("Enter the size of the frame:\n");
	scanf("%d",&framesize);

	for(int i=0;i<framesize;i++)
	{
		frame[i] = -1;
		priority[i] = -1;
	}

	for(int i=0;i<numberofsearch;i++)
	{
		if(searchframe(search[i]))
		{
			frame[location] = search[i];
			priority[location] = count;
			count++;
		}
		else
		{
			fault++;
			int index = position();
			frame[index] = search[i];
			priority[index] = count;
			count++;
		}

		for(int j=0;j<framesize;j++)
		{
			printf("%d     ",frame[j]);
		}
		printf("Page Fault: %d\n",fault);
	}
}