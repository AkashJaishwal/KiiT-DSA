#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *preptr;
    struct node *nextptr;
} * stnode, *ennode;

void create(int n);
void displayRev();

int main()
{
    system("cls");
    int n;
    stnode = NULL;
    ennode = NULL;
    printf("\n\n * * *  DOUBLY LINKED LIST  * * *     \n");
    printf(" ------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    printf("\n");

    create(n);
    displayRev();
    system("pause");
    return 0;
}

void create(int n)
{
    int i, num;
    struct node *fnNode;

    if (n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));

        if (stnode != NULL)
        {
            printf(" Enter Node 1 : ");
            scanf("%d", &num);

            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode;
            for (i = 2; i <= n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if (fnNode != NULL)
                {
                    printf(" Enter Node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode;
                    fnNode->nextptr = NULL;

                    ennode->nextptr = fnNode;
                    ennode = fnNode;
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}
void displayRev()
{
    struct node *tmp;
    int n = 0;
    if (ennode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = ennode;
        printf("\n Reverse Linked List Data are :\n");

        while (tmp != NULL)
        {
            printf(" Node %d : %d\n", n+1, tmp->num);
            n++;
            tmp = tmp->preptr;
        }
    }
}