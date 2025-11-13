#include <stdio.h>
#include <pthread.h>

#define SIZE 10

int data[SIZE] = {5, 12, 7, 3, 19, 21, 9, 14, 2, 8};
int sum = 0;
int max = 0;
void* calculate_sum(void* arg) {
    int temp_sum = 0;
    for (int i = 0; i < SIZE; i++) {
        temp_sum += data[i];
    }
    sum = temp_sum;
    pthread_exit(NULL);
}

void* find_max(void* arg) {
    int temp_max = data[0];
    for (int i = 1; i < SIZE; i++) {
        if (data[i] > temp_max)
            temp_max = data[i];
    }
    max = temp_max;
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, calculate_sum, NULL);
    pthread_create(&thread2, NULL, find_max, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Sum of array elements: %d\n", sum);
    printf("Maximum element: %d\n", max);

    return 0;
}