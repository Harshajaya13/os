#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#define n 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (i + 4) % n
#define RIGHT (i + 1) % n

sem_t s[n];   // this is allowing that specific semaphores to take operation
sem_t mutex;  // this is way of syntax giving using semaphores
int state[n]; // whether eating or thinking or hungery,easily used in the if
              // condition
int phil[n] = {0, 1, 2, 3, 4};

void test(int i) {
  if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
    state[i] = EATING;
    sleep(2);
    printf("philosopher %d takes fork %d and %d \n", i, LEFT, RIGHT);
    printf("philosopher %d is EATING \n", i);
    sem_post(&s[i]);
  }
}

void takefork(int i) {
  sem_wait(&mutex); // using wait
  state[i] = HUNGRY;
  printf("philosopher %d is HUNGRY\n", i + 1);
  test(i);
  sem_post(&mutex); // clearing mutex
  sem_wait(&s[i]);  // waiting the semaphore[i]
  sleep(1);
}

void putfork(int i) {
  sem_wait(&mutex);
  state[i] = THINKING;
  printf("Philosopher %d puts down forks %d and %d and starts THINKING\n",
         i + 1, LEFT + 1, i + 1);
  test(LEFT);
  test(RIGHT);
  sem_post(&mutex);
}

void *philo(void *num) {
  int i = *(int *)num;
  while (1) {

    sleep(1);
    takefork(i);
    sleep(0);
    putfork(i);
  }
}

int main() {
  int i;
  pthread_t thread_id[n];
  sem_init(&mutex, 0, 1); // initialising mutex
  for (int i = 0; i < n; i++) {
    pthread_create(&thread_id[i], NULL, philo, &phil[i]);
    printf("philosopher %d is THINKING\n", i + 1);
  }
  for (int i = 0; i < n; i++) {
    pthread_join(thread_id[i], NULL);
  }
  return 0;
}
