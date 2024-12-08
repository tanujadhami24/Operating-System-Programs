// Implementation of FIRST COME FIRST SERVED SCHEDULING ALGO.

#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{ wt[0] = 0;
for (int i = 1; i < n; i++) {
     wt[i] = wt[i - 1] + bt[i - 1];
     }
     }

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
     for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        }
        }

void findAverageTime(int processes[], int n, int bt[]) { 
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0; 
    findWaitingTime(processes, n, bt, wt); 
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
    for (int i = 0; i < n; i++) {
    total_wt += wt[i]; 
    total_tat += tat[i];
    printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
     printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / n); 
     printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
     }


int main() {
     int n;
    printf("Enter the number of processes: "); 
    scanf("%d", &n);
    int processes[n], burst_time[n];
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; 
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        } 
    findAverageTime(processes, n, burst_time); return 0;}
