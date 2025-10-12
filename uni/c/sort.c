#include <stdio.h>

#define N 4
#define NO_INSERT -1

int main() {
    int input, inputs[N];
    int insert_idx = NO_INSERT;

    for (int i = 0; i < N; i++) {
        scanf("%d", &input);

        // find insertion point
        for (int j = 0; j < i; j++) {
            if (inputs[j] > input) {
                insert_idx = j;
                break;
            }
        }

        // append only
        if (insert_idx == NO_INSERT) {
            inputs[i] = input;
            continue;
        }

        // shift right
        for (int j = N - 1; j > insert_idx; j--) {
            inputs[j] = inputs[j - 1];
        }

        // insert
        inputs[insert_idx] = input;
        insert_idx = NO_INSERT;
    }

    return 0;
}
