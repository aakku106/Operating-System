#include <stdio.h>

int main() {
    printf("Rijan Shrestha\n\n\n");
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], finish[n];

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<m;i++)
        scanf("%d", &avail[i]);

    for(i=0;i<n;i++)
        finish[i] = 0;

    int flag;
    do {
        flag = 0;
        for(i=0;i<n;i++) {
            if(finish[i] == 0) {
                int canFinish = 1;
                for(j=0;j<m;j++) {
                    if(max[i][j] - alloc[i][j] > avail[j]) {
                        canFinish = 0;
                        break;
                    }
                }
                if(canFinish) {
                    for(k=0;k<m;k++)
                        avail[k] += alloc[i][k];
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
    } while(flag);

    printf("Deadlocked processes: ");
    int deadlock = 0;
    for(i=0;i<n;i++) {
        if(finish[i] == 0) {
            printf("%d ", i);
            deadlock = 1;
        }
    }
    if(!deadlock) printf("None");
    printf("\n");
    return 0;
}
