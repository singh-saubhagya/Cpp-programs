#include<stdio.h>

typedef struct process {
    int pid;
    int burst_time;
    int arrival_time;
} Process;

void findWaitingTime(Process proc[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n ; i++ )
        wt[i] = proc[i-1].burst_time + wt[i-1] - proc[i].arrival_time;
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n ; i++)
        tat[i] = proc[i].burst_time + wt[i];
}

void findavgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    printf("Processes Burst time Waiting time Turn around time\n");
    for (int i=0; i<n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, wt[i], tat[i]);
    }
    printf("Average waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %.2f", (float)total_tat / (float)n);
}

int main() {
    Process proc[] = {{1, 10, 1}, {2, 5, 3}, {3, 8, 2}};
    int n = sizeof proc / sizeof proc[0];

    // Sorting processes by arrival time.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrival_time > proc[j].arrival_time) {
                Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    findavgTime(proc, n);
    return 0;
}
