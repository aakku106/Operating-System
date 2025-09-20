#include <stdio.h>

int main() {
    printf("Rijan Shrestha\n\n\n");

    int n = 5, m = 3;
    int alloc[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int avail[3] = {3,3,2};
    int need[5][3];
    int finish[5] = {0};
    int i, j, k;
    
    // Calculate Need matrix
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];
    
    int safeSeq[5], count = 0;
    
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int flag=1;
                for(j=0;j<m;j++){
                    if(need[i][j] > avail[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    safeSeq[count++] = i;
                    for(j=0;j<m;j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                }
            }
        }
    }
    
    printf("Safe Sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    
    return 0;
}
