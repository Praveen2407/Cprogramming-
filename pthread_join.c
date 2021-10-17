/*************************************
Praveen R

pthread_join will suspend execution of the thread that has called it unless the target thread terminates. 

thread join is for a parent (P -main) to join with one of its child threads (C - thread_fnc). 
Thread join has the following activities, assuming that a parent thread P wants to join with one of its child threads C:

When P executes a thread join in order to join with C, which is still running, P is suspended until C terminates. Once C terminates, P resumes.
When P executes a thread join and C has already terminated, P continues as if no such thread join has ever executed (i.e., join has no effect).
**************************************/



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_fnc(void * arg);

char thread_msg[] ="Hello Thread!";  // global

int main()
{
        int ret;
        pthread_t my_thread;
        void *ret_join;

        ret =  pthread_create(&my;_thread, NULL, thread_fnc, (void*) thread_msg);
        if(ret != 0) {
                perror("pthread_create failed\n");
                exit(EXIT_FAILURE);
        }
        printf("Waiting for thread to finish...\n");
        ret = pthread_join(my_thread, &ret_join);
        if(ret != 0) {
                perror("pthread_join failed");
                exit(EXIT_FAILURE);
        }
        printf("Thread joined, it returned %s\n", (char *) ret_join);
        printf("New thread message: %s\n",thread_msg);
        exit(EXIT_SUCCESS);
}

void *thread_fnc(void *arg)
{
        printf("This is thread_fnc(), arg is %s\n", (char*) arg);
        strcpy(thread_msg,"Bye!");
        pthread_exit("'Exit from thread'");
}
