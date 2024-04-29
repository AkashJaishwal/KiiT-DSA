/*
Home Assignment
/7/
WAP to find out the kth smallest and kth largest element stored in a dynamic
array of n integers, where k<n.
*/
#include<stdio.h>

void find(int a[20],int n,int k,int l)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("The sorted list is: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    if(l==1)
    {
        for(i=n-1;i>=n-k;i--);
        printf("\nThe %dth largest element is: %d",k,a[i+1]);
    }
    else
    {
        for(i=0;i<k;i++);
        printf("\nThe %dth smallest element is: %d",k,a[i-1]);
    }
}
int main()
{
    int i,n,a[20],k,l;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the value of k: ");
    scanf("%d",&k);
    printf("Enter 1 for kth largest or 0 for kth smallest: ");
    scanf("%d",&l);
    find(a,n,k,l);
}