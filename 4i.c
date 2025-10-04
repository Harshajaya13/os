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
    printf("%c -------------%d  ----------- %d\n", ch++, at[i],
           bt[i]); // this prints the processes and thier bt and at
  }

  // this is for finding the values only
  printf("\t\t | 0 | ");

  for (int i = 0; i < n; i++) {
    if (t < at[i]) { // CPU Idle till process arrives
      idle += (at[i] - t);
      t = at[i];
    }

    t += bt[i];
    ct[i] = t;
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    avgWt += wt[i];
    avgTat += tat[i];
  }

  printf("\nGhantt Chart :\n");
  printf("=============\n\n");

  for (i = 0; i < n; i++) {
    printf(" | %c ", 'A' + i);
  }
  printf("\n");
  printf("0");
  for (i = 0; i < n; i++) {
    printf("   %d", ct[i]);
  }
  printf("\n");
  // for printing individually
  printf("\n\n process ---- waiting time\n");
  ch = 'A';
  for (i = 0; i < n; i++) {
    printf("%c -------------------- %d\n", ch, wt[i]);
    ch++;
  }
  printf("\n\n process -------- turn around time\n");
  ch = 'A';
  for (i = 0; i < n; i++) {
    printf("%c ------------------ %d\n", ch, tat[i]);
    ch++;
  }
  // final outputs
  printf("\nAverage turn around time is : %2lf", avgTat / n);
  printf("\nAverage waiting time is : %2lf", avgWt / n);

  return 0;
}
