
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
struct node* findMin(struct node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node* deleteNode(struct node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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
    printf("\nInorder before deletion: ");
    inorder(root);
    printf("\nEnter the node to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    printf("\nInorder after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}