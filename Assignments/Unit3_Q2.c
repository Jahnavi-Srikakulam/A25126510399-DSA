/*Develop a C program for a Doubly Linked List representing a sequence of web pages
visited by a user. The program should insert a new page, move forward and backward,
delete a specified page, and display the pages from first-to-last and last-to-first
while handling beginning and end conditions correctly. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[50];
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;
struct node* tail = NULL;
struct node* createNode(char value[])
{
    struct node* newnode = malloc(sizeof(struct node));
    strcpy(newnode->data, value);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insertEnd(char value[])
{
    struct node* newnode = createNode(value);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    printf("Page inserted successfully!!\n");
}
void moveForward(char key[])
{
    struct node* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->data, key) == 0)
        {
            if(temp->next == NULL)
            {
                printf("Already at the last page.\n");
            }
            else
            {
                printf("Moved forward to: %s\n", temp->next->data);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Page not found!!\n");
}
void moveBackward(char key[])
{
    struct node* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->data, key) == 0)
        {
            if(temp->prev == NULL)
            {
                printf("Already at the first page.\n");
            }
            else
            {
                printf("Moved backward to: %s\n", temp->prev->data);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Page not found!!\n");
}
void deleteNode(char key[])
{
    struct node* temp = head;
    while(temp != NULL && strcmp(temp->data, key) != 0)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Page not found!!\n");
        return;
    }
    if(temp == head)
    {
        head = temp->next;
        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
    }
    else if(temp == tail)
    {
        tail = temp->prev;
        tail->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    printf("%s is deleted.\n", temp->data);
    free(temp);
}
void displayforward()
{
    struct node* temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Pages from first to last:\n");
    while(temp != NULL)
    {
        printf("%s <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void displayBackward()
{
    struct node* temp;
    if(tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = tail;
    printf("Pages from last to first:\n");
    while(temp != NULL)
    {
        printf("%s <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main()
{
    int choice;
    char value[50];
    char key[50];
    while(1)
    {
        printf("\n***Menu***\n");
        printf("1. Insert a new page\n");
        printf("2. Move forward\n");
        printf("3. Move backward\n");
        printf("4. Delete a page\n");
        printf("5. Display forward\n");
        printf("6. Display backward\n");
        printf("7. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter page name: ");
                scanf("%s", value);
                insertEnd(value);
                break;
            case 2:
                printf("Enter current page: ");
                scanf("%s", key);
                moveForward(key);
                break;
            case 3:
                printf("Enter current page: ");
                scanf("%s", key);
                moveBackward(key);
                break;
            case 4:
                printf("Enter page to delete: ");
                scanf("%s", key);
                deleteNode(key);
                break;
            case 5:
                displayforward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}