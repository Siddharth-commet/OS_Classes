#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // Size of the bounded buffer

int buffer[BUFFER_SIZE];
int in = 0, out = 0;  // Indexes for producer and consumer

sem_t empty;  // Counts empty slots in buffer
sem_t full;   // Counts filled slots in buffer
pthread_mutex_t mutex;  // For mutual exclusion

// Function for Producer thread
void* producer(void* arg) {
    int item;
    for (int i = 1; i <= 10; i++) {
        item = rand() % 100;  // Produce an item

        sem_wait(&empty);              // Wait for empty slot
        pthread_mutex_lock(&mutex);    // Enter critical section

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&full);               // Signal that buffer has new item

        sleep(1); // Simulate production time
    }
    return NULL;
}

// Function for Consumer thread
void* consumer(void* arg) {
    int item;
    for (int i = 1; i <= 10; i++) {
        sem_wait(&full);               // Wait for available item
        pthread_mutex_lock(&mutex);    // Enter critical section

        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&empty);              // Signal that buffer has empty slot

        sleep(2); // Simulate consumption time
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Clean up
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    printf("All threads finished successfully.\n");
    return 0;
}
