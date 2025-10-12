#include <limits.h>
#include <stdio.h>

// fifo

int lru() {
  int incoming[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
  int n = sizeof(incoming) / sizeof(incoming[0]);
  int f = 3;
  int distance[n];
  int queue[n];
  int occupied = 0;
  int pagefault = 0;

  printf("Page\t Frame1 \t Frame2 \t Frame3\n");
  for (int i = 0; i < n; i++) {

    printf("%d: \t\t", incoming[i]); // print the value first

    if (checkHit(incoming[i], queue, occupied)) {
      printframe(queue, occupied);
    }

    else if (occupied < f) {
      queue[occupied] = incoming[i];
      pagefault++;
      occupied++;
      printframe(queue, occupied);
    } else {
      int max = -1, index = -1;
      for (int j = 0; j < f; j++) {
        distance[j] = 0;

        for (int k = i - 1; k >= 0; k--) {
          distance[j]++;
          if (queue[j] == incoming[k]) {
            break;
          }
          if (distance[j] > max) {
            max = distance[j];
            index = j;
          }
        }
        queue[index] = incoming[i];
        pagefault++;
        printframe(queue, occupied);
      }
    }
  }
  printf("Page Fault in LRU : %d\n\n", pagefault);
  return pagefault;
}

// optimal

int search(int key, int items[], int occupied) {
  for (int i = 0; i < occupied; i++) {
    if (items[i] == key) {
      return 1;
    }
  }
  return 0;
}

printf("stream\t\tFrame1\t\tFrame2\t\tFrame3");

void currframe(int item, int items[], int occupied, int max) {
  printf("\n%d \t\t", item);
  for (int i = 0; i < max; i++) {
    if (i < occupied) {
      printf("%d \t\t", items[i]);
    } else {
      printf("- \t\t");
    }
  }
}

int predict(int ref[], int items[], int reflen, int index, int occupied) {
  int result = -1, farthest = index;
  for (int i = 0; i < occupied; i++) {
    int j;
  }
}
