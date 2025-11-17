#include <stdio.h>

#define SIZE 28

int main() {
    int i, tomb[SIZE];
    
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &tomb[i]);
    }
    
    for (i = 0; i < SIZE; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", tomb[i]);
    }
    printf("\n");
    
    return 0;
}
