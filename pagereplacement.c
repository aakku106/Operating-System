#include <stdio.h>

int main() {
    int n, frames, i, j, k;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string: ");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);
    
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    
    // ---------------- FIFO ----------------
    int fifo_mem[frames], fifo_pos = 0, fifo_faults = 0;
    for(i=0;i<frames;i++) fifo_mem[i]=-1;
    for(i=0;i<n;i++){
        int hit=0;
        for(j=0;j<frames;j++) if(fifo_mem[j]==pages[i]) hit=1;
        if(!hit){ fifo_mem[fifo_pos]=pages[i]; fifo_pos=(fifo_pos+1)%frames; fifo_faults++; }
    }
    printf("FIFO Page Faults: %d\n", fifo_faults);
    
    // ---------------- Optimal ----------------
    int opt_mem[frames]; for(i=0;i<frames;i++) opt_mem[i]=-1;
    int opt_faults=0;
    for(i=0;i<n;i++){
        int hit=0;
        for(j=0;j<frames;j++) if(opt_mem[j]==pages[i]) hit=1;
        if(!hit){
            int empty=-1;
            for(j=0;j<frames;j++) if(opt_mem[j]==-1){ empty=j; break; }
            if(empty!=-1) opt_mem[empty]=pages[i];
            else{
                int farthest=-1, replace=-1;
                for(j=0;j<frames;j++){
                    int found=0;
                    for(k=i+1;k<n;k++){ if(opt_mem[j]==pages[k]){ found=k; break; } }
                    if(found==0) found=n+1;
                    if(found>farthest){ farthest=found; replace=j; }
                }
                opt_mem[replace]=pages[i];
            }
            opt_faults++;
        }
    }
    printf("Optimal Page Faults: %d\n", opt_faults);
    
    // ---------------- LRU ----------------
    int lru_mem[frames], time[frames]; for(i=0;i<frames;i++){ lru_mem[i]=-1; time[i]=0; }
    int lru_faults=0;
    for(i=0;i<n;i++){
        int hit=0;
        for(j=0;j<frames;j++){
            if(lru_mem[j]==pages[i]){ hit=1; time[j]=i; break; }
        }
        if(!hit){
            int lru_index=0, min_time=10000;
            for(j=0;j<frames;j++){
                if(lru_mem[j]==-1){ lru_index=j; break; }
                if(time[j]<min_time){ min_time=time[j]; lru_index=j; }
            }
            lru_mem[lru_index]=pages[i]; time[lru_index]=i; lru_faults++;
        }
    }
    printf("LRU Page Faults: %d\n", lru_faults);
    
    return 0;
}
