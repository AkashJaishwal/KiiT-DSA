/*
Home Assignment
/4/
Write a program to replace every element in the dynamic array with the
next greatest element present in the same array.
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,n,i,j,max;
	printf("Enter size of array:");
	scanf("%d",&n);

	a=malloc(sizeof(int)*n);

	printf("Enter %d Elements:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n-1;i++)
	{
		max=a[i+1];
		for(j=i+2;j<n;j++)
		{
			if(a[j]>max)
			{
				max=a[j];
			}
		}
		a[i]=max;
	}
	printf("Output Result :\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
				
}