#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3, x = 0, y = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces item %d\n", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    y++;
    printf("Consumer consumes item %d\n", y);
    ++mutex;
}

int main() {
    int n, i;

    printf("1. Press 1 for Producer\n");
    printf("2. Press 2 for Consumer\n");
    printf("3. Press 3 for Exit\n");

    #pragma omp critical
    for (i = 1; i > 0; i++) {
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full!\n");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty!\n");
                }
                break;

            case 3:
                exit(0);
                break;
        }
    }

    return 0;
}
