#include <stdio.h>

#define MAX_H 23
#define MAX_M 59

int main() {
    int h, m;
    while(scanf("%d %d", &h, &m) == 0 || h < 0 || h > MAX_H || m < 0 || m > MAX_M);
    printf("%d %d\n", h, m);

    return 0;
}
