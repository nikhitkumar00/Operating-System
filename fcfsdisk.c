#include <stdio.h>
#include <stdlib.h>

void main()
{
    int numberofsearch,head,movement=0;
    int sequence[15];

    printf("\nEnter the number of search sequence you wish to enter:\n");
    scanf("%d",&numberofsearch);

    printf("Enter the sequence in order\n");
    for(int i=0;i<numberofsearch;i++)
    {
        scanf("%d",&sequence[i]);
    }

    printf("Enter the present head position\n");
    scanf("%d",&sequence[-1]);

    for(int i=0;i<numberofsearch;i++)
    {
        movement = movement + abs(sequence[i-1] - sequence[i]);
    }

    printf("Total head movement is:\n%d",movement);
}