#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addatfirst(struct node *start, int data);
struct node *addatend(struct node *start, int data);
int largest(struct node *start);
int smallest(struct node *start);

int main()
{
    system("cls");
    struct node *start = NULL;
    int n;

    start = create_list(start);
    display(start);
    printf("\nLargest Element is %d\n", largest(start));
    printf("\nSmallest Element is %d\n", smallest(start));

    return 0;
}

int largest(struct node *ptr)
{
    int large = ptr->data;
    while (ptr != NULL)
    {
        if (ptr->data > large)
            large = ptr->data;
        ptr = ptr->link;
    }
    return large;
}

int smallest(struct node *ptr)
{
    int small = ptr->data;
    while (ptr != NULL)
    {
        if (ptr->data < small)
            small = ptr->data;
        ptr = ptr->link;
    }
    return small;
}

struct node *create_list(struct node *start)
{
    int i, n, data;
    printf("Enter the number of Elements to Enter : ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;

    printf("\nEnter Element : ");
    scanf("%d", &data);
    start = addatfirst(start, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter Element : ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    p = start;
    printf("\nThe Elements are :\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n\n");
}

struct node *addatfirst(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->link = start;
    start = tmp;
    return start;
}

struct node *addatend(struct node *start, int data)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = tmp;
    tmp->link = NULL;
    return start;
}