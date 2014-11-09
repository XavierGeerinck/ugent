#include <stdio.h>
#include <pthread.h>

void * print_number(void * number);

int main() {
    int x1 = 0, x2 = 1, x3 = 2, x4 = 3;
    pthread_t print_thread;

    pthread_create(&print_thread, NULL, print_number, &x1);
    pthread_create(&print_thread, NULL, print_number, &x2);
    pthread_create(&print_thread, NULL, print_number, &x3);
    pthread_create(&print_thread, NULL, print_number, &x4);

    pthread_join(print_thread, NULL);

    printf("Done");
}

void * print_number(void * number) {
    int i = 0;

    for (i = 0; i < 100; i++) {
        printf("%d\n", *(int *) number);
    }
}