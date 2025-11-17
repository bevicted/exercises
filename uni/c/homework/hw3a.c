#include <stdio.h>

#define INPUT_SIZE 10
#define COUNTER_SIZE 100

int main() {
    int input, counter[100] = {0};

    for (int i = 0; i < INPUT_SIZE; i++) {
        scanf("%d", &input);
        counter[input]++;
    }

    for (int i = 0; i < INPUT_SIZE; i++) {
        scanf("%d", &input);
        counter[input]--;
    }

    for (int i = 0; i < COUNTER_SIZE; i++) {
        if (counter[i] > 0) printf("%d\n", i);
    }
}
