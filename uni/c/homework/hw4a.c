#include <stdio.h>

#define INPUT_SIZE 10

int main() {
    int arr1[INPUT_SIZE], arr2[INPUT_SIZE];

    for (int i = 0; i < INPUT_SIZE; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < INPUT_SIZE; i++) {
        scanf("%d", &arr2[i]);
    }

    int arr1_smallest = arr1[0];
    for (int i = 0; i < INPUT_SIZE; i++) {
        if (arr1[i] < arr1_smallest)
            arr1_smallest = arr1[i];
    }

    int arr2_smallest = arr2[0];
    for (int i = 0; i < INPUT_SIZE; i++) {
        if (arr2[i] < arr2_smallest)
            arr2_smallest = arr2[i];
    }

    if (arr1_smallest > arr2_smallest) {
        printf("ELSO\n%d\n", arr1_smallest);
    } else if (arr2_smallest > arr1_smallest) {
        printf("MASODIK\n%d\n", arr2_smallest);
    } else {
        printf("EGYENLO\n%d\n", arr1_smallest);
    }

    return 0;
}

