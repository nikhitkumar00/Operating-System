#include <stdio.h>
#include<stdlib.h>

	int limit,head,numberofsearches;
	int list[15];
	int index=0,movement=0,temp,choice;

void hightolow()
{
	temp = head;
	for(int i=index;i>=0;i--)
	{
		movement = movement + abs(temp - list[i]);
		temp = list[i];
	}

	movement = movement + list[0];

	temp=0;
	for(int i = index+1;i<numberofsearches;i++)
	{
		movement = movement + abs(list[i] - temp);
		temp = list[i];
	}

	printf("\n\nTotal Head Movement is: \n%d",movement);
}

void lowtohigh()
{
	temp = head;
	for(int i = index+1;i<numberofsearches;i++)
	{
		movement = movement + abs(list[i] - temp);
		temp = list[i];
	}

	movement = movement + abs(limit - list[numberofsearches-1]);

	temp = limit;
	for(int i = index;i>=0;i--)
	{
		movement = movement + abs(list[i] - temp);
		temp = list[i];
	}

	printf("\n\nTotal Head Movement is: \n%d",movement);
}

void main()
{
	printf("\nEnter the limit of the Disk:\n");
	scanf("%d",&limit);

	printf("Enter the current head position:\n");
	scanf("%d",&head);

	printf("Enter the number of searches that you wish to enter:\n");
	scanf("%d",&numberofsearches);

	printf("Enter the search sequence in order:\n");
	for(int i=0;i<numberofsearches;i++)
	{
		scanf("%d",&list[i]);
	}

	for(int i=0;i<numberofsearches-1;i++)
	{
		for(int j=0;j<numberofsearches-i-1;j++)
		{
			if(list[j] > list[j+1])
			{
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	
	for(int i=0;i<numberofsearches;i++)
	{
		if(list[i]<head)
		{
			index = i;
		}
	}

	printf("Enter your choice\n1: High to low\n2: Low to high\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: 
			hightolow();
			break;

		case 2:
			lowtohigh();
			break;

		default:
			exit(0);
	}
}