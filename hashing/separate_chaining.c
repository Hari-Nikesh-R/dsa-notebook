#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Node for the separate chaining linked lists
struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

// Initialize hash table with NULLs
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Insert value using modulo hashing and separate chaining
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    int key = value % SIZE;

    if (hashTable[key] == NULL) {
        hashTable[key] = newNode;
    } else {
        // Collision happened: Append to the linked list
        struct Node* temp = hashTable[key];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Print the chained hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = hashTable[i];
        printf("Bucket[%d] --> ", i);
        while (temp) {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    init();
    insert(7);
    insert(0);
    insert(3);
    insert(10); // Collides with 0 (10 % 10 == 0)
    insert(4);
    insert(20); // Collides with 0
    insert(5);
    
    display();
    return 0;
}
