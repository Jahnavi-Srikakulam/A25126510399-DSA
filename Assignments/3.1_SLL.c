/*A department maintains student roll numbers dynamically.
Write a C program using a Singly Linked List to create the list,
insert at the beginning and end, search for a specified roll number,
delete a specified roll number, and display the updated list after each operation.
Handle the case when a requested roll number is not available.*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int roll;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int roll)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    return newNode;
}
void insertBeginning(int roll)
{
    struct Node *newNode = createNode(roll);
    newNode->next = head;
    head = newNode;
    printf("Roll number %d inserted at beginning.\n", roll);
}
void insertEnd(int roll)
{
    struct Node *newNode = createNode(roll);
    struct Node *temp;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Roll number %d inserted at end.\n", roll);
}
void search(int roll)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Roll number %d found.\n", roll);
            return;
        }
        temp = temp->next;
    }
    printf("Roll number %d not found.\n", roll);
}
void delete(int roll)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (head == NULL)
    {
        printf("List is empty. Roll number %d not found.\n", roll);
        return;
    }
    if (head->roll == roll)
    {
        head = head->next;
        free(temp);
        printf("Roll number %d deleted.\n", roll);
        return;
    }
    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Roll number %d not found.\n", roll);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Roll number %d deleted.\n", roll);
}
void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Student roll numbers: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, roll;
    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Search roll number\n");
        printf("4. Delete roll number\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                display();
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                display();
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                display();
                break;
            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                delete(roll);
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
