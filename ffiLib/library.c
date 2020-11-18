#include "library.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

pthread_mutex_t counterMutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER;

typedef struct threadArgs_tag {
    int id;
    const char *msg;
    int out;
    callback_t callback;
} threadArgs_t;

int count = 0;
threadArgs_t argsAdd[MAX_THREADS];
pthread_t threads[MAX_THREADS]; // XXX: use Malloc

void* add(callback_t callback) {
    argsAdd[count].id = count;
    argsAdd[count].msg = "Message";
    argsAdd[count].callback = callback;
    count++;
    return 0;
}

void* run(void *args) {
    threadArgs_t *arg = (threadArgs_t*) args;

    int len;

    if (arg->msg == NULL) {
        return BAD_MESSAGE;
    }

    len = strlen(arg->msg);
    //printf("%s\n", arg->msg);
    arg->out = len;

    //pthread_mutex_lock(&counterMutex);
    arg->callback(arg->id);
    //pthread_mutex_unlock(&counterMutex);
    //pthread_detach(pthread_self());

    //pthread_exit(NULL);
    return SUCCESS;
}


int start() {
    int i;
    int status;
    int status_addr;

    printf("Count Threads = %d\n", count);

    //threads = (pthread_t*) malloc(count+1 * sizeof(pthread_t));

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);


    for (i = 0; i < count; i++) {
        status = pthread_create(&threads[i], NULL, run, (void*) &argsAdd[i]);

        if (status != 0) {
            printf("main error: can't create thread, status = %d\n", status);
            return 0;
        }
    }


    for (i = 0; i < count; i++) {
        status = pthread_join(threads[i], NULL);
        if (status != SUCCESS) {
            printf("main error: can't join thread, status = %d\n", status);
            return 0;
        }
    }

    return 0;
}

