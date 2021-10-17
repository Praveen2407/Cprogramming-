/*****************************
Praveen R
pthread_exit 

Case 1 : If we dont porvide pthread_exit() function,they will be automatically terminated when main() finishes.
Case 2 : If main() finishes before the threads it has created, and exits with pthread_exit(),the other threads will continue to execute.
*****************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *worker_thread(void *arg)
{
        printf("This is worker_thread()\n");
        pthread_exit(NULL);
}

int main()
{
        pthread_t my_thread;
        int ret;

        printf("In main: creating thread\n");
        ret =  pthread_create(&my_thread, NULL, &worker_thread, NULL);
        if(ret != 0) {
                printf("Error: pthread_create() failed\n");
                exit(EXIT_FAILURE);
        }
       pthread_exit(NULL);
}
