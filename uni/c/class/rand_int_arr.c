#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// caller owns memory
int* new_rand_int_arr(int size, int min, int max) {
    int* arr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        arr[i] = rand_int(min, max);
    
    return arr;
}

int sum_int_arr(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

void enlarge(int **p_arr, int *p_size, int new_size) {
    *p_arr = (int*)realloc(*p_arr, sizeof(int) * new_size);
    for (int i = *p_size; i < new_size; i++)
        (*p_arr)[i] = rand_int(10, 20);
    *p_size = new_size;
}

int main() {
    srand(time(NULL));

    int size = rand_int(10, 20);
    printf("SIZE: %d\n", size);
    int* arr = new_rand_int_arr(size, 0, 50);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("SUM: %d\n", sum_int_arr(arr, size));

    enlarge(&arr, &size, size + rand_int(2, 6));

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("SUM: %d\n", sum_int_arr(arr, size));

    free(arr);

    return 0;
}
