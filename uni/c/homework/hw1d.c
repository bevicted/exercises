#include <stdio.h>

#define NO_INSERT -1

#define LEN 3
#define CMP <

int main() {
    int input, inputs[LEN];
    int insert_idx = NO_INSERT;

    for (int i = 0; i < LEN; i++) {
        scanf("%d", &input);

        // find insertion point
        for (int j = 0; j < i; j++) {
            if (inputs[j] CMP input) {
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
        for (int j = LEN - 1; j > insert_idx; j--) {
            inputs[j] = inputs[j - 1];
        }

        // insert
        inputs[insert_idx] = input;
        insert_idx = NO_INSERT;
    }

    for (int i = 0; i < LEN; i++)
        printf("%d ", inputs[i]);

    printf("\n");

    return 0;
}
