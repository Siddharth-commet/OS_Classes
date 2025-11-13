#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int shared_var = 0;
sem_t mutex;            
void* thread_func(void* arg) {
    char* thread_name = (char*)arg;

    for (int i = 0; i < 5; i++) {
        sem_wait(&mutex);
        int temp = shared_var;
        printf("%s entered critical section. Shared_var = %d\n", thread_name, temp);
        temp++;
        sleep(1);
        shared_var = temp;
        printf("%s leaving critical section. Updated shared_var = %d\n\n", thread_name, shared_var);
        sem_post(&mutex);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    sem_init(&mutex, 0, 1);

    pthread_create(&t1, NULL, thread_func, "Thread 1");
    pthread_create(&t2, NULL, thread_func, "Thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);

    printf("Final value of shared_var = %d\n", shared_var);

    return 0;
}