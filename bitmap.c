#include <stdio.h>
#include <stdlib.h>

#define BLOCKS 16  // total memory blocks

int main() {
    printf("Rijan Shrestha\n\n\n");
    
    unsigned int bitmap = 0; // each bit represents a memory block (0 = free, 1 = allocated)
    int choice, block;

    while(1) {
        printf("\nMemory Bitmap: ");
        for(int i=BLOCKS-1;i>=0;i--) {
            printf("%d", (bitmap >> i) & 1);
        }
        printf("\n");

        printf("\n1. Allocate block\n2. Free block\n3. Exit\nChoose: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter block number to allocate (0-%d): ", BLOCKS-1);
            scanf("%d", &block);
            if(block<0 || block>=BLOCKS) {
                printf("Invalid block number!\n");
                continue;
            }
            if(bitmap & (1<<block)) {
                printf("Block already allocated!\n");
            } else {
                bitmap |= (1<<block); // set bit
                printf("Block %d allocated.\n", block);
            }
        }
        else if(choice == 2) {
            printf("Enter block number to free (0-%d): ", BLOCKS-1);
            scanf("%d", &block);
            if(block<0 || block>=BLOCKS) {
                printf("Invalid block number!\n");
                continue;
            }
            if(bitmap & (1<<block)) {
                bitmap &= ~(1<<block); // clear bit
                printf("Block %d freed.\n", block);
            } else {
                printf("Block is already free!\n");
            }
        }
        else if(choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
