/*
Home Assignment
/5/
WAP to replace every dynamic array element by multiplication of previous
and next of an n element.
*/
#include<stdio.h> 
void newArryPrevNext(int arr1[], int n) 
{ 
    if (n <= 1) 
      return; 
    int pre_elem = arr1[0]; 
    arr1[0] = arr1[0] * arr1[1]; 
    for (int i=1; i<n-1; i++) 
    { 
        int cur_elem = arr1[i]; 
        arr1[i] = pre_elem * arr1[i+1]; 
        pre_elem = cur_elem; 
    } 
    arr1[n-1] = pre_elem * arr1[n-1]; 
} 
int main() 
{ 
    int arr1[] = {1,2, 3, 4, 5, 6}; 
    int n = sizeof(arr1)/sizeof(arr1[0]); 
	int i = 0; 
	printf("The given array is:  \n");
	for(i = 0; i < n; i++)
		{
			printf("%d  ", arr1[i]);
		}
    printf("\n");
	printf("The new array is: \n");	
    newArryPrevNext(arr1, n); 
    for (int i=0; i<n; i++) 
      printf("%d ", arr1[i]); 
    return 0; 
}