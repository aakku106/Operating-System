#include <stdio.h>

#define SIZE 5  // Buffer size

int buffer[SIZE];
int count = 0;  // Number of items in buffer

// Function to produce an item
void produce(int item) {
    if(count == SIZE) {
        printf("Buffer is full! Cannot produce %d\n", item);
    } else {
        buffer[count] = item;
        count++;
        printf("Produced: %d\n", item);
    }
}

// Function to consume an item
void consume() {
    if(count == 0) {
        printf("Buffer is empty! Cannot consume\n");
    } else {
        int item = buffer[count-1];
        count--;
        printf("Consumed: %d\n", item);
    }
}

int main() {
    // Simulate producing and consuming items
    produce(1);
    produce(2);
    produce(3);
    consume();
    produce(4);
    consume();
    consume();
    consume();
    consume();  // Trying to consume from empty buffer
    return 0;
}
