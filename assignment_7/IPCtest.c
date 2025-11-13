#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main() {
void *shared_memory;
char buff[100];
int shmid;
shmid = shmget((key_t)11222, 1024, 0666 | IPC_CREAT);
printf("Key of shared memory is %d\n", shmid);
shared_memory = shmat(shmid, NULL, 0);
printf("Process attached at %p\n", shared_memory);
printf("Enter data to write\n");
read(0, buff, sizeof(buff));
strcpy(shared_memory, buff);
printf("Producer wrote: %s\n", (char *)shared_memory);
return 0;
}