#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
};
struct node *start = NULL;

void create()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        exit(0);
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void traverse()
{
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("\nData = %d\n", temp->info);
        temp = temp->next;
    }
}
int main()
{
    system("cls");
    int choice;
    while (1)
    {
        printf("\n* * *  DOUBLY LINKED LIST  * * *     \n");
        printf("\n\t1. To Creat\n");
        printf("\n\t2. To Display\n");
        printf("\n\t3. Exit\n");
        printf("\n--------------------------------------\n");

        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            traverse();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}