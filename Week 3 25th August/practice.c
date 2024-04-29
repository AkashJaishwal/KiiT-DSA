// WAP in menu driven form to travarse a linked list,find largest and smallest element/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};  
void travarse(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("->%d",ptr->data);
        ptr=ptr->next;
    }
}
void largest(struct node* ptr)
{
    int max=0;
    while(ptr!=NULL)
    {
        if((max)<(ptr->data))
        {
            max=ptr->data;
        }
        ptr=ptr->next;
    } 
    printf("%d\n",max);   
}
void smallest(struct node* ptr)
{
    long int min=999999999;
    while(ptr!=NULL)
    {
        if((min)>(ptr->data))
        {
            min=ptr->data;
        }
        ptr=ptr->next;
    } 
    printf("%d\n",min);   
}

int main()
{
    struct node *prev,*head=NULL,*p;
    int n,time;
    printf ("\nNumber of elements:- ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        //printf("Enter data-%d - ",i);
        p->data=rand()%100;
        //scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
        }  
        else
        {
            prev->next=p;
        }
       prev=p;
    }
    
    int choice;
    printf("\nEnter 1 to travarse the linked list");
    printf("\nEnter 2 to to find the largets element in the linked list");
    printf("\nEnter 3 to to find the smallest element in the linked list");
    printf("\n\nENTER YOUR CHOICE - \n");
    scanf("%d",&choice);
    switch(choice)
   {
       case 1:{
       printf("The inputed linked list is - \n"); 
       travarse(head);
       break;
       }
       case 2:{
       printf("\n\nThe largest element in the list is - ");
       largest(head);
       break;
       }
       case 3:{
       printf("\n\nThe smallest element in the list is - ");
       smallest(head);
       break;
       }
    }
    printf("\n\n");
    return 0;
}