#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void tarverse(struct Node *ptr)
{

    printf("List items\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {

            if (ptr1->data == ptr2->next->data)
            {

                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
int main()
{
    system("cls");
    int size, i, key;
    printf("Enter the number of nodes you want: ");

    scanf("%d", &size);

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data: ");
    scanf("%d", &head->data);
    head->next = NULL;
    struct Node *point = (struct Node *)malloc(sizeof(struct Node));
    point = head;
    for (i = 1; i < size; i++)
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &(node->data));
        node->next = NULL;
        point->next = node;
        point = point->next;
    }
    printf("\nBefore Removing Duplicates: \n");
    tarverse(head);
    removeDuplicates(head);
    printf("\nAfter Removing Duplicates: \n");
    tarverse(head);
    printf("\n");
    system("pause");
    return 0;
}