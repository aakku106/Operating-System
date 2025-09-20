#include <stdio.h>
#include <stdlib.h>

// Structure for memory block
struct Block {
    int id;             // Block number or process ID
    int size;           // Size of block
    struct Block* next; // Pointer to next block
};

// Create a new memory block
struct Block* createBlock(int id, int size) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->id = id;
    newBlock->size = size;
    newBlock->next = NULL;
    return newBlock;
}

// Allocate block at the end of list
void allocateBlock(struct Block** head, int id, int size) {
    struct Block* newBlock = createBlock(id, size);
    if(*head == NULL) {
        *head = newBlock;
        return;
    }
    struct Block* temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newBlock;
    printf("Allocated block %d of size %d\n", id, size);
}

// Deallocate block by ID
void deallocateBlock(struct Block** head, int id) {
    struct Block* temp = *head;
    struct Block* prev = NULL;

    if(temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Deallocated block %d\n", id);
        return;
    }

    while(temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Block %d not found\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deallocated block %d\n", id);
}

// Display memory blocks
void displayBlocks(struct Block* head) {
    struct Block* temp = head;
    printf("Memory Blocks:\n");
    while(temp != NULL) {
        printf("Block ID: %d, Size: %d\n", temp->id, temp->size);
        temp = temp->next;
    }
}

int main() {
    struct Block* memory = NULL;

    allocateBlock(&memory, 1, 100);
    allocateBlock(&memory, 2, 200);
    allocateBlock(&memory, 3, 300);

    displayBlocks(memory);

    deallocateBlock(&memory, 2);
    displayBlocks(memory);

    deallocateBlock(&memory, 5); // not present

    return 0;
}
