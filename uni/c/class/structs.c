#include <stdio.h>
#include <stdlib.h>

struct date {
    int y, m, d;
};

typedef struct date Date;

int main() {
    Date d1 = {
        .y = 2025,
        .m = 11,
        .d = 7,
    };
    Date d2 = {
        .y = 2026,
        .m = 1,
        .d = 1,
    };
    return 0;
}
