#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int number = *(int *)arg;

    printf("Thread %d is executing\n", number);

    for (int i = 1; i <= 5; i++)
    {
        printf("Thread %d: %d\n", number, i);
    }

    printf("Thread %d has completed\n", number);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    int number1 = 1;
    int number2 = 2;

    /* Create two threads and pass arguments */
    pthread_create(&thread1, NULL, thread_function, &number1);
    pthread_create(&thread2, NULL, thread_function, &number2);

    /* Wait for both threads to complete */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have completed.\n");

    return 0;
}