/*A service centre uses a fixed-size request buffer in which released positions
must be reused. Write a C program to implement a Circular Queue using an array
with insertion, deletion, display, overflow and underflow operations. 
Demonstrate that positions freed after deletion can be reused for new requests. */
#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}
int isEmpty() {
    return (front == -1);
}
void enqueue(int value)
{
    if (isFull())
        {
        printf("Queue Overflow\n");
        return;
        }
    if (isEmpty())
        {
        front = 0;
        }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
    printf("Insertion success!!\n");
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear)
        {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue : ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
         break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
int main()
{
   int value,choice;
   while(1)
   {
   printf("\n***Menu***\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter the choice:");
   scanf("%d",&choice);
   
    switch(choice)
    {
        case 1:printf("enter the value:");
               scanf("%d",&value);
               enqueue(value);
               break;
        case 2:dequeue();
               break;
        case 3:displayQueue();
                break;
        case 4:exit(0);
        default:printf("Invalid choice!!\n");
    }
   }
return 0;
}
