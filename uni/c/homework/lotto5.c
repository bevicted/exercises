#include <stdio.h>

#define N 10
#define M 5

int main() {
    unsigned int tickets[N][M];
    unsigned int winning_nums[M];
    unsigned int winnings[M + 1] = {0, 0, 1800, 14600, 1212400, 109567000};
    unsigned int total_winnings = 0;
    unsigned int guess_count[91] = {0}; // inefficient but I just want out

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &tickets[i][j]);

    for (int i = 0; i < M; i++)
        scanf("%d", &winning_nums[i]);

    // O(N * M^2) :(
    for (int n = 0; n < N; n++) {
        int hits = 0;
        for (int m = 0; m < M; m++) {
            guess_count[tickets[n][m]]++;
            for (int w = 0; w < M; w++)
                if (tickets[n][m] == winning_nums[w]) {
                    hits++;
                    break;
                }
        }
        printf("%d. szelveny: %d talalat\n", n + 1, hits);
        total_winnings += winnings[hits];
    }

    printf("\nA teljes nyert osszeg: %d\n", total_winnings);
    unsigned int count = 0, guess = 0;
    for (int i = 0; i < 90; i++)
        if (guess_count[i] > count) {
            count = guess_count[i];
            guess = i;
        }

    printf("A leggyakrabban tippelt szam: %d\n", guess);

    return 0;
}
