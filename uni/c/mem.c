#include <stdio.h>
#include <stdlib.h>

int main() {
    // int amount;
    // printf("How many numbers to work with? ");
    // scanf("%d", &amount);
    //
    // double *arr = malloc(sizeof(int) * amount);
    // for (int i = 0; i < amount; i++)
    //     scanf("%lf", &arr[i]);
    // for (int i = 0; i < amount; i++)
    //     printf("%lf\n", arr[i]);
    //
    // free(arr);

    char *cities[10];
    char temp[1000];
    scanf("%s", temp);
    int len = 0;
    while (temp[len] != '\0') len++;
    char *text = malloc((sizeof(char) + 1) * len);

    for (int i = 0; i < len; i++)
        text[i] = temp[i];
    text[len] = '\0';

    printf("%s\n", text);

    free(text);

    return 0;
}
