#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    for (int i = 0; i < n; i++) {
        printf("Arrival time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // remaining time starts as burst
    }

    int complete = 0, time = 0;
    float sumTAT = 0, sumWT = 0;

    while (complete < n) {
        int shortest = -1;
        int minRT = INT_MAX;

        // pick process with shortest remaining time so far
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minRT) {
                minRT = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++; // no process ready yet
        } else {
            rt[shortest]--;
            time++;

            if (rt[shortest] == 0) {
                complete++;
                ct[shortest] = time;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];
                sumTAT += tat[shortest];
                sumWT += wt[shortest];
            }
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f\n", sumTAT / n);
    printf("Average WT  = %.2f\n", sumWT / n);

    return 0;
}
