#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define Nthreads 5

int counter = 0;
pthread_mutex_t mutex;

void *thread_function(void *arg) {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread ID: %ld, Counter value: %d\n", pthread_self(), counter);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[Nthreads];
    int i;

    if (pthread_mutex_init(&mutex, NULL) != 0) {
        fprintf(stderr, "Error initializing mutex\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < Nthreads; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < Nthreads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    if (pthread_mutex_destroy(&mutex) != 0) {
        fprintf(stderr, "Error destroying mutex\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
