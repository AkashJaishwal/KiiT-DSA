/*Create a linked list and enter an element at any index in the list*/

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
struct node* insertatanindex(struct node* head,int data,int index)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    ptr->data=data;
    while(i!=(index-1))
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    
}

int main()
{
    system("cls");
    struct node *prev,*head=NULL,*p;
    int n,n2,index;
    printf ("\nNumber of elements:- ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=rand()%100;
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
    printf("\nThe entered linked list is-\n");
    travarse(head);
    printf("\n\nEnter the value you want to insert at an index in between -\n");
    scanf("%d",&n2);
    printf("\n\nEnter the index where the value is to be inserted-\n");
    scanf("%d",&index);    
    insertatanindex(head,n2,index);
    printf("\n\nList after inserting the data after %d node-\n",index);
    travarse(head);
    return 0;
}