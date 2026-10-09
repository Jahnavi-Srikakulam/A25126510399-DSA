#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *createNode(int value)
{
struct node *newnode=malloc(sizeof(struct node));
newnode -> data = value;
newnode -> next = NULL;
}
void enqueue(int value)
{
struct node *newnode = createNode(value);
if(front==NULL&&rear==NULL)
{
front=rear=newnode;
}
else
{
rear -> next = newnode;
rear = newnode;
printf("The value %d is enqueued",value);
}
}
void dequeue()
{
struct node *temp;
if(front==NULL)
{
printf("The queue is empty");
return;
}
temp = front;
front=front->next;
printf("The dequeued element is:%d\n",front->data);
free(temp);
}
void display()
{
struct node *temp;
if(front==NULL&&rear==NULL)
{
printf("The queue is empty");
return;
}
temp = front;
while(temp!=NULL)
{
printf("%d<->",temp->data);
temp=temp->next;
}
}
int main()
{
int value,choice;
while(1)
{
printf("\n***Menu***\n1.Enqueue\n2.Dequeue\n3.Display\n");
printf("Enter choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter value to insert:");
       scanf("%d",&value);
       enqueue(value);
       break;
case 2:dequeue();
       break;
case 3:display();
       break;
case 4:exit(0);
default: 
printf("\nInvalid choice");
}
}
return 0;
}
