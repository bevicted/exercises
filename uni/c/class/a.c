#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double max(double a, double b) {
    if (a > b) return a;
    return b;
}

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double rand_double(int min, int max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}

// caller owns memory
double* new_rand_int_arr(int size, int min, int max) {
    double* arr = malloc(sizeof(double) * size);

    for (int i = 0; i < size; i++)
        arr[i] = rand_double(min, max);
    
    return arr;
}

int max_index(double *arr, int len) {
    int idx = 0;
    for (int i = 0; i < len; i++)
        if (arr[i] > arr[idx]) idx = i;
    return idx;
}

int main() {
    srand(time(NULL));

    double input_a = 12.3, input_b = 13.2;

    double input_max = max(23, 100);
    printf("%.2lf\n", input_max);

    double arr[3] = {10.5, 12.2, 0.01};
    printf("idx: %d\n", max_index(arr, 3));

    int rand_arr_size = rand_int(10, 20);

    printf("ARR SIZE: %d\n", rand_arr_size);

    double* rand_arr = new_rand_int_arr(rand_arr_size, 0, 100);

    for (int i = 0; i < rand_arr_size; i++) {
        printf("%lf ", rand_arr[i]);
    }
    printf("\n");

    int max_idx = max_index(rand_arr, rand_arr_size);
    printf("MAX IDX: %d\n", max_idx);

    free(rand_arr);

    return 0;
}
