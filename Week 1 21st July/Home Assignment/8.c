/*
Home Assignment
/8/
WAP to find the largest number and counts the occurrence of the largest
number in a dynamic array of n integers using a single loop.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
int arrayNum[15];
int a;
int max=0;
int location;
for( a=0; a < 15; a++)
    {   
        printf("Enter element %d:", a);
        scanf("%d",&arrayNum[a]);
    }

for(a=0; a < 15; a++)
    {
        printf("%d\n", arrayNum[a]);
    }

for (a = 1; a < 15; a++)
  {
    if (arrayNum[a] > max)
    {
       max  = arrayNum[a];
       location = a+1;
    }
    }
printf("Max element in the array in the location %d and its value %d\n", location, max);
int NoOfOccurances;
NoOfOccurances = 0;
for(a=0; a<15; a++)
    {
        if(max == arrayNum[a])
        {
             NoOfOccurances++;
        }  

    }

 printf("Number %d: %d occurences\n", max,NoOfOccurances);
return 0;
}