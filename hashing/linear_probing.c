#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int hashTable[SIZE];
bool isOccupied[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
        isOccupied[i] = false;
    }
}

// Insert value using linear probing
void insert(int key) {
    int index = key % SIZE;
    int startIndex = index;
    
    // Probe systematically until an empty slot is found
    while (isOccupied[index]) {
        index = (index + 1) % SIZE; // Linear search
        
        // Return if we looped around without finding space
        if (index == startIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    
    hashTable[index] = key;
    isOccupied[index] = true;
    printf("Inserted %d at index %d\n", key, index);
}

// Search for a specific key
void search(int key) {
    int index = key % SIZE;
    int startIndex = index;
    
    while (isOccupied[index]) {
        if (hashTable[index] == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        
        if (index == startIndex) {
            break;
        }
    }
    printf("%d not found in hash table\n", key);
}

// Print the table contents
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (isOccupied[i]) {
            printf("[%d] : %d\n", i, hashTable[i]);
        } else {
            printf("[%d] : ~~Empty~~\n", i);
        }
    }
}

int main() {
    init();
    insert(5);
    insert(15); // Collision with 5, moves to index 6
    insert(25); // Collision with 5 and 15, moves to index 7
    insert(1);
    
    printf("\nHash Table Dump:\n");
    display();
    
    printf("\nSearch Results:\n");
    search(15);
    search(100);
    return 0;
}
