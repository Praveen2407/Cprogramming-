/***************************
Praveen R

The mutual exclusion lock is the simplest and most primitive synchronization variable. 
It provides a single, absolute owner for the section of code (aka a critical section) that it brackets
between the calls to pthread_mutex_lock() and pthread_mutex_unlock().

A mutex lock is a mechanism that can be acquired by only one thread at a time. For other threads to get the same mutex, 
they must wait until it is released by the current owner of the mutex.
********************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

volatile int counter = 0;
pthread_mutex_t myMutex;

void *mutex_testing(void *param)
{
        int i;
        for(i = 0; i < 5; i++) {
                pthread_mutex_lock(&myMutex);
                counter++ ;
                usleep(1);
                printf("thread %d counter = %d\n", (int)param,  counter);
                pthread_mutex_unlock(&myMutex);
        }
}

int main()
{
        int one = 1, two = 2, three = 3;
        pthread_t thread1, thread2, thread3;
        pthread_mutex_init(&myMutex,0);
        pthread_create(&thread1, 0, mutex_testing, (void*)one);
        pthread_create(&thread2, 0, mutex_testing, (void*)two);
        pthread_create(&thread3, 0, mutex_testing, (void*)three);
        pthread_join(thread1, 0);
        pthread_join(thread2, 0);
        pthread_join(thread3, 0);
        pthread_mutex_destroy(&myMutex);
        return 0;
}
