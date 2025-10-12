#include <stdio.h>

int main() {
    int num, base, remainder;
    scanf("%d %d", &num, &base);

    remainder = num % base;
    if (remainder < base >> 1) {
        printf("%d\n", num - remainder);
        return 0;
    }

    printf("%d\n", num + base - remainder);
    return 0;
}
