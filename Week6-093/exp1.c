#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Thread is executing\n");

    for (int i = 1; i <= 5; i++)
    {
        printf("Thread: %d\n", i);
    }

    printf("Thread has completed\n");

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    /* Create two threads */
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    /* Wait for both threads to complete */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have completed.\n");

    return 0;
}