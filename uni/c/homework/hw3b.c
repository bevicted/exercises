#include <stdio.h>

#define INPUT_SIZE 8

int main() {
    int arr1[INPUT_SIZE], arr2[INPUT_SIZE], x;

    for (int i = 0; i < INPUT_SIZE; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < INPUT_SIZE; i++) {
        scanf("%d", &arr2[i]);
    }

    scanf("%d", &x);

    for (int i = 0; i < INPUT_SIZE; i++) {
        int hit_1 = arr1[i] == x;
        int hit_2 = arr2[i] == x;
        if (hit_1 & hit_2) {
            printf("EGYENLO %d", i);
            return 0;
        } else if (hit_1) {
            printf("1 %d", i);
            return 0;
        } else if (hit_2) {
            printf("2 %d", i);
            return 0;
        }
    }

    printf("NINCS\n");

    return 0;
}
