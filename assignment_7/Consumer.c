#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
int main() {
    void *shared_memory;
    int shmid;
    shmid = shmget((key_t)11222, 1024, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }
    printf("Process attached at %p\n", shared_memory);
    printf("Consumer read: %s\n", (char *)shared_memory);
    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        exit(1);
    } else {
        printf("Shared memory detached successfully.\n");
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl (remove) failed");
        exit(1);
    } else {
        printf("Shared memory deleted successfully.\n");
    }
    return 0;
}