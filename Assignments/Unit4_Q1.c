/*A system stores unique integer identification numbers using a Binary Search Tree.
Write a C program to insert n values, display inorder, preorder and postorder traversals,
search for a specified value, and report whether it exists.
Use the output to explain why inorder traversal produces sorted values. */
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int value)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }
    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void search(struct node* root, int key)
{
    if(root == NULL)
    {
        printf("%d does not exist in the BST.\n", key);
        return;
    }
    if(root->data == key)
    {
        printf("%d exists in the BST.\n", key);
        return;
    }
    if(key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}
int main()
{
    struct node* root = NULL;
    int n, value, key, i;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\n\nEnter the value to search: ");
    scanf("%d", &key);
    search(root, key);
    printf("Inorder traversal gives sorted order of values because BST stores smaller values in left subtree and greater values in right subtree.\n");
    return 0;
}