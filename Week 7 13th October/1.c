#include <stdio.h>
#include <conio.h>
#define max 20

int q[max];
int front = -1, rear = -1;
void ins(int);
int del();
void display();
int isempty();
int isfull();

void main()
{
    int ch, item, x;
    char a;
    printf("\n\t Queue Implementation");
    printf("\n\t --------------------");
    printf("\n\t1.Enqueue");
    printf("\n\t2.Dequeue");
    printf("\n\t3.Display");
    printf("\n\t4.IsEmpty");
    printf("\n\t5.IsFull");
    do
    {
        printf("\n\t Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Element to Insert:\n");
            scanf("%d", &item);
            ins(item);
            break;
        case 2:
            x = del();
            printf("The Element Deleted from Queue is %d", x);
            break;
        case 3:
            display();
            break;
        case 4:
            x = isempty();
            if (x == 1)
                printf("Queue is Empty");
            else
                printf("Queue is Not Empty");
            break;
        case 5:
            x = isfull();
            if (x == 1)
                printf("Queue is Full");
            else
                printf("Queue is Not Full");
            break;
        default:
            printf("INVALID Choice\n");
        }
        printf("\n Do You want to continue y/n: ");
        scanf(" %c", &a);
    } while ((a == 'y') || (a == 'Y'));
    getch();
}

void ins(int x)
{
    if (rear == max - 1)
        printf("Queue is OVERFLOW \n");
    else if (rear == -1)
    {
        front = 0;
        rear = 0;
        q[rear] = x;
    }
    else
    {
        rear++;
        q[rear] = x;
    }
}

int del()
{
    int x;
    if (front == -1)
        printf("Queue is UNDERFLOW \n");
    else if (front == rear)
    {
        x = q[front];
        front = -1;
        rear = -1;
        return (x);
    }
    else
    {
        x = q[front];
        front++;
        return (x);
    }
}

void display()
{
    int i;
    if (rear == -1)
        printf("\n Queue is Empty");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t", q[i]);
    }
}

int isempty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (rear == max - 1)
        return 1;
    else
        return 0;
}