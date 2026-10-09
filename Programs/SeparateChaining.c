#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct Node {
int data;
struct Node* next;
} Node;
Node* hashTable[TABLE_SIZE];
int hash(int key) {
return key % TABLE_SIZE; }
void insert(int key) {
int index = hash(key);
Node* newNode = (Node*)malloc(sizeof(Node));
if (!newNode) {
printf("Memory allocation failed\n");
return;
}
newNode->data = key;
newNode->next = hashTable[index];
hashTable[index] = newNode;
printf("Inserted %d at index %d\n", key, index);
}
int search(int key) {
int index = hash(key);
Node* temp = hashTable[index];
while (temp) {
if (temp->data == key)
return 1;
temp = temp->next;
}
return 0;
}
void delete(int key) {
int index = hash(key);
Node* temp = hashTable[index];
Node* prev = NULL;
while (temp) {
if (temp->data == key) {
if (prev)
prev->next = temp->next;
else
hashTable[index] = temp->next;
free(temp);
printf("Deleted %d from index %d\n", key, index);
return;
}
prev = temp;
temp = temp->next;
}
printf("Key %d not found\n", key);
}
void display() {
for (int i = 0; i < TABLE_SIZE; i++) {
printf("Index %d:", i);
Node* temp = hashTable[i];
while (temp) {
printf(" %d ->", temp->data);
temp = temp->next;
}
printf(" NULL\n");
}
}
int main() {
for (int i = 0; i < TABLE_SIZE; i++)
hashTable[i] = NULL;
insert(15);
insert(25);
insert(35);
insert(20);
insert(30);
display();
printf("Search for 25: %s\n", search(25) ? "Found" : "Not Found");
printf("Search for 40: %s\n", search(40) ? "Found" : "Not Found");
delete(25);
delete(40);
display();
return 0;
}