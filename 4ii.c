#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, i;
  char ch = 'A';
  double avgWt = 0, avgTat = 0;
  printf("enter the number of processes");
  scanf("%d", &n);
  int at[n], bt[n];
  int tat[n], wt[n], ct[n], t = 0, idle = 0;
  int done[n], seq[n];
  printf("enter the arrival time of the  processes: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &at[i]);
  }
  printf("enter the burst time of the processes: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &bt[i]);
  }

  printf("======= ========== ============\n");
  printf("Process Burst TIme Arrival Time\n");
  printf("======= ========== ============\n");

  for (i = 0; i < n; i++) {
    printf("%c --- %d  --- %d", ch++, at[i],
           bt[i]); // this prints the processes and thier bt and at
  }

  // this is for finding the values only
  int completed = 0;
  for (i = 0; i < n; i++)
    done[i] = 0;
  while (completed < n) {
    int minBT = 1000;
    int minIndex = -1;
    for (i = 0; i < n; i++) {
      if (!done[i] && at[i] <= t) {
        if (bt[i] < minBT) {
          minBT = bt[i];
          minIndex = i;
        }
      }
    }

    if (minIndex == -1) {
      // no process has arrived yet → CPU idle
      t++;
      continue;
    }

    seq[completed] = minIndex;
    t += bt[minIndex]; // process runs completely
    ct[minIndex] = t;
    tat[minIndex] = ct[minIndex] - at[minIndex];
    wt[minIndex] = tat[minIndex] - bt[minIndex];
    avgWt += wt[minIndex];
    avgTat += tat[minIndex];
    done[minIndex] = 1; // mark as done
    completed++;
  }

  printf("\nGhantt Chart :\n");
  printf("=============\n\n");

  for (i = 0; i < n; i++) {
    printf(" | %c |", 'A' + seq[i]);
  }
  printf("\n");
  printf("0");
  for (i = 0; i < n; i++) {
    printf("   %d\t\t", ct[seq[i]]);
  }
  printf("\n");
  // for printing individually
  printf("\n\n process ---- waiting time");
  ch = 'A';
  for (i = 0; i < n; i++) {
    printf("%c ---- %d", ch, wt[i]);
    ch++;
  }
  printf("\n\n process ----- turn around time");
  ch = 'A';
  for (i = 0; i < n; i++) {
    printf("%c ------ %d", ch, tat[i]);
    ch++;
  }
  // final outputs
  printf("\nAverage turn around time is : %2lf", avgTat / n);
  printf("\nAverage waiting time is : %2lf", avgWt / n);

  return 0;
}
