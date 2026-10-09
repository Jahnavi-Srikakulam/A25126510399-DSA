#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void enqueue();
void dequeue();
void display();
char queue_arr[MAX];
int rear = -1;
int front = -1;
void main()
{
    int choice;
    while (1)
    {
        printf("\n****MENU****\n");
        printf("\n\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Selection!");
        }
    }
}
void enqueue()
{
    char add_item;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        printf("Element to be inserted: ");
        scanf(" %c", &add_item);
        rear = rear + 1;
        queue_arr[rear] = add_item;
        printf("Insertion Success!!\n");
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("%c is deleted\n", queue_arr[front]);
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        int i;

        printf("The Queue Elements are:\n");

        for (i = front; i <= rear; i++)
            printf("%c\n", queue_arr[i]);
    }
}