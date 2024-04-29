/*
Lab Assignment
/Q7/ Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.*/

#include <stdio.h>
#include <stdlib.h>
void non(int **arr, int n)
{
    int non = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                non++;
            }
        }
    }
    printf("\nThe number of nonzero elements is %d\n", non);
}
void sum(int **arr, int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + arr[i][j];
        }
    }
    printf("\nThe sum of the elements above the leading diagonal is %d\n",sum);
}
void minor(int **arr, int n)
{
    int sum = 0;
    int f = n-2;
    printf("\nThe elements below the minor diagonal are \n");
    for (int i = 1; i <n;i++)
    {
        for (int j = n-1; j >f;j--)
        {
            printf("%d ",arr[i][j]);
        }
        f--;
    }
}
void product(int **arr, int n) 
{
    int k = 1;
    for (int i = 0; i < n;i++)
    {
        for (int j = i; j == i;j++)
        {
            k = k * arr[i][j];
        }
    }
    printf("\n\nThe product of the diagonal elements is %d\n", k);
}
int main()
{
    int n, i, j;
    int **arr;
    printf("\nEnter the size of the  square matrix A[ n x n ]\n");
    scanf("%d", &n);
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    int g = 1;
    for (i = 0; i < n; i++)
    {
    printf("Enter %d Element in Row %d\n", n,(g++));
    for (j = 0; j < n; j++)
    {
        scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    printf("The Matrix is\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    non(arr, n);
    sum(arr, n);
    minor(arr, n);
    product(arr, n);
    return 0;
}