#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()

#define CHAIRS 3     // number of waiting chairs
#define CUSTOMERS 5  // total customers

int main() {
    int waiting = 0; // number of waiting customers

    for (int i = 1; i <= CUSTOMERS; i++) {
        printf("Customer %d arrives.\n", i);

        if (waiting < CHAIRS) {
            waiting++;
            printf("Customer %d is waiting. Waiting = %d\n", i, waiting);

            // Barber cuts hair for this customer
            printf("Barber is cutting hair of Customer %d...\n", i);
            sleep(2); // haircut time
            printf("Customer %d is done and leaves.\n", i);

            waiting--; // customer served, leaves chair
        } else {
            printf("Customer %d found no empty chair and left.\n", i);
        }

        sleep(1); // gap before next customer arrives
    }

    printf("All customers processed.\n");
    return 0;
}
