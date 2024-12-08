// Implementation of SHORTEST JOB FIRST SCHEDULING ALGO.

#include <stdio.h>

void sjfScheduling(int processes[], int n, int bt[]) { 
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
for (int i = 0; i < n - 1; i++) { 
    for (int j = i + 1; j < n; j++) {
if (bt[i] > bt[j]) {
     int temp = bt[i]; 
     bt[i] = bt[j]; 
     bt[j] = temp;
temp = processes[i]; 
processes[i] = processes[j]; 
processes[j] = temp;
}
}
}
wt[0] = 0;
for (int i = 1; i < n; i++) { 
    wt[i] = wt[i - 1] + bt[i - 1];
    }
for (int i = 0; i < n; i++) { 
    tat[i] = bt[i] + wt[i]; 
    total_wt += wt[i]; 
    total_tat += tat[i];
    }
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
for (int i = 0; i < n; i++) {
printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
} 
printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / n); 
printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}


int main() { 
    int n;
printf("Enter number of processes: "); 
scanf("%d", &n);

int processes[n], bt[n];
 printf("Enter burst times:\n"); 
 for (int i = 0; i < n; i++) {
processes[i] = i + 1;
 printf("P%d: ", i + 1);
scanf("%d", &bt[i]);
} 
sjfScheduling(processes, n, bt); 
return 0;
}
