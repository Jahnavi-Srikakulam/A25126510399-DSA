#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top=NULL;
struct node *createNode(int value)
{
struct node *newnode=malloc(sizeof(struct node));
newnode -> data = value;
newnode -> next = NULL;
}
void push(int value)
{
struct node *newnode = createNode(value);
newnode -> next = top;
top = newnode;
printf("The value %d is pushed",value);
}
void pop()
{
struct node *temp;
if(top==NULL)
{
printf("The stack is empty");
return;
}
temp = top;
printf("The popped element is:%d\n",top->data);
top=top->next;
free(temp);
}
void peek()
{
if(top==NULL)
{
printf("The stack is empty");
return;
}
printf("The top element is:%d\n",top->data);
}
void display()
{
struct node *temp;
if(top==NULL)
{
printf("The stack is empty");
return;
}
temp = top;
if(temp!=NULL)
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
printf("\n***Menu***\n1.Push\n2.Pop\n3.Peek\n4.Display\n");
printf("Enter choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter value to insert:");
       scanf("%d",&value);
       push(value);
       break;
case 2:pop();
       break;
case 3:peek();
       break;
case 4:display();
       break;
case 5:exit(0);
default: 
printf("\nInvalid choice");
}
}
return 0;
}
