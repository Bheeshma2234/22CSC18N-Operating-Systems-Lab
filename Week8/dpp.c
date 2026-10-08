#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];
sem_t room;

void *philosopher(void *arg)
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;

    printf("Philosopher %d is thinking\n", id);
    sleep(1);

    printf("Philosopher %d is hungry\n", id);

    sem_wait(&room);

    sem_wait(&forks[left]);
    printf("Philosopher %d picked fork %d\n", id, left);

    sem_wait(&forks[right]);
    printf("Philosopher %d picked fork %d\n", id, right);

    printf("Philosopher %d is eating\n", id);
    sleep(1);

    sem_post(&forks[right]);
    sem_post(&forks[left]);
    sem_post(&room);

    printf("Philosopher %d finished eating\n", id);

    return NULL;
}

int main()
{
    pthread_t t[N];
    int id[N];

    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    sem_init(&room, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&t[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    for (int i = 0; i < N; i++)
        sem_destroy(&forks[i]);

    sem_destroy(&room);

    return 0;
}
