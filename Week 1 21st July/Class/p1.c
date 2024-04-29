#include <stdio.h>
#include <stdlib.h>
void main(){

    int a=10;
    int *p=&a;
    printf("a=%d\n",a); // Direct access of value
    printf("a=%d\n",*p); // Indirect access of value
    *p=20;
    printf("a=%d\n",a); // Direct access of value
    printf("a=%d\n",*p); // Indirect access of value
    p=NULL;
    p=(int*)malloc(sizeof(int));
    *p=30;
    printf("a=%d\n",a); // Direct access of value
    printf("a=%d\n",*p); // Indirect access of value
}