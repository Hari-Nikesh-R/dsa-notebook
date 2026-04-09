#include <stdio.h>

#define SIZE 10

// 1. Our Hash Table (Locker Room)
// We initialize it with -1 to mean "Empty"
int hashTable[SIZE] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

// Helper function to print the hash table
void printTable() {
    printf("Locker Room (Hash Table):\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("[Locker %d]: Empty\n", i);
        } else {
            printf("[Locker %d]: Student ID %d\n", i, hashTable[i]);
        }
    }
    printf("\n");
}

// 2. The Insert Action with our Magic Formula!
void insert(int studentID) {
    // Our Hash Function: Get the last digit
    int index = studentID % SIZE;
    
    printf("Trying to place Student %d in Locker %d...\n", studentID, index);
    
    // 3. Check for Collisions!
    // If the locker is not empty (-1), keep moving to the next one
    while (hashTable[index] != -1) {
        printf("Oops, Locker %d is full! Moving to the next one...\n", index);
        index = (index + 1) % SIZE; // Move right, wrap around back to 0 if needed
    }
    
    // We found an empty locker!
    hashTable[index] = studentID;
    printf("Success! Put Student %d in Locker %d.\n\n", studentID, index);
}

int main() {
    printf("--- Welcome to Hashing School ---\n\n");
    
    // Normal inserts
    insert(452); // Goes to index 2
    insert(187); // Goes to index 7
    insert(990); // Goes to index 0
    
    // Uh oh, a collision!
    insert(342); // Wants 2, but 2 is taken by 452. Will move to 3!
    
    // A chain reaction collision!
    insert(113); // Wants 3, but 3 is now taken by 342. Will move to 4!
    
    printTable();
    
    return 0;
}
