// Implementation of First comes first serve page replacement policy

#include <stdio.h>

void fcfsPageReplacement(int pages[], int n, int capacity) { 
    int frame[capacity], front = 0, count = 0;
    for (int i = 0; i < capacity; i++) 
        frame[i] = -1;
    printf("Page\tFrames\n"); 
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) { 
            if (frame[j] == pages[i]) {
                found = 1; 
                break;
                }
                }
        if (!found) {
            frame[front] = pages[i];
            front = (front + 1) % capacity; count++;
            }
        printf("%d\t", pages[i]);
        for (int j = 0; j < capacity; j++) 
        if (frame[j] != -1)
printf("%d ", frame[j]);
printf("\n");}
printf("\nTotal Page Faults: %d\n", count);

} int main() {
int n, capacity;
printf("Enter number of pages: "); scanf("%d", &n);
int pages[n]; printf("Enter pages: "); for (int i = 0; i < n; i++)
scanf("%d", &pages[i]); printf("Enter frame capacity: "); scanf("%d", &capacity); fcfsPageReplacement(pages, n, capacity); return 0;}
