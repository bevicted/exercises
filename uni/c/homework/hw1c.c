#include <stdio.h>

#define LEN 4
#define Y "YES\n"
#define N "NO\n"

int main() {
    int inputs[LEN], sum;
    for (int i = 0; i < LEN; i++) {
        scanf("%d", &inputs[i]);
        sum += inputs[i];
    }

    for (int i = 0; i < LEN; i++) {
        if (inputs[i] == sum - inputs[i]) {
            printf(Y);
            return 0;
        }
        for (int j = i + 1; j < LEN; j++) {
            int two_sum = inputs[i] + inputs[j];
            if (two_sum == sum - two_sum) {
                printf(Y);
                return 0;
            }
        }
    }

    printf(N);
    return 0;
}
