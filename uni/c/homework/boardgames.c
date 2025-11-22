#include <stdio.h>

# define N 8
#define uint unsigned int
#define ushort unsigned short

struct {
    char name[52];
    float rating;
    uint release_year;
    ushort player_min;
    ushort player_max;
} typedef Boardgame;

Boardgame scanfBoardgame() {
    Boardgame b;
    scanf("%s", b.name);
    scanf("%u", &b.release_year);
    scanf("%f", &b.rating);
    scanf("%hu", &b.player_min);
    scanf("%hu", &b.player_max);
    return b;
}

void printfBoardgame(Boardgame b) {
    printf(
            "%s (%u): rating: %.1f, players: %hu-%hu\n",
            b.name,
            b.release_year,
            b.rating,
            b.player_min,
            b.player_max
    );
}

int main() {
    Boardgame boardgames[N];
    Boardgame oldest;

    // 1
    for (int i = 0; i < N; i++) {
        boardgames[i] = scanfBoardgame();
        // 4 prep
        if (i == 0 || boardgames[i].release_year < oldest.release_year)
            oldest = boardgames[i];
    }

    // 2
    printf("All data:\n");
    for (int i = 0; i < N; i++)
        printfBoardgame(boardgames[i]);

    // 3
    printf("\n5 player games:\n");
    for (int i = 0; i < N; i++)
        if (boardgames[i].player_min <= 5 && boardgames[i].player_max >= 5)
            printf("%s\n", boardgames[i].name);

    // 4
    printf("\nThe oldest game: %s\n\n", oldest.name);

    // 5
    Boardgame temp;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (boardgames[j].rating > boardgames[i].rating) {
                temp = boardgames[i];
                boardgames[i] = boardgames[j];
                boardgames[j] = temp;
            }

    printf("Sorted by rating:\n");
    for (int i = 0; i < N; i++)
        printfBoardgame(boardgames[i]);

    return 0;
}
