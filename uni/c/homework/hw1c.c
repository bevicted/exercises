#include <stdio.h>

#define N 4
#define C 10 // 4C2 + 4C3

int main() {
    int inputs[N], sums[C];
    for (int i = 0; i < N; i++) {
        scanf("%d", &inputs[i]);
    }

    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            sums[idx++] = inputs[i] + inputs[j];
            for (int k = j + 1; k < N; k++) {
                sums[idx++] = inputs[i] + inputs[j] + inputs[k];
            }
        }
    }

    for (int i = 0; i < C; i++) {
        for (int j = i + 1; j < C; j++) {
            if (sums[i] == sums[j]) {
                printf("IGEN\n");
                return 0;
            }
        }
    }
    printf("NEM\n");

    return 0;
}
