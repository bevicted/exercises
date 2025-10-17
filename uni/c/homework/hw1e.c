#include <stdio.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void print_steps(char message[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s\n", message);
}

int main() {
    int player_x, player_y;
    int goal_x, goal_y;
    scanf("%d %d", &player_x, &player_y);
    scanf("%d %d", &goal_x, &goal_y);

    int steps[4];

    steps[UP] = goal_y - player_y;
    steps[RIGHT] = goal_x - player_x;
    steps[DOWN] = player_y - goal_y;
    steps[LEFT] = player_x - goal_x;

    print_steps("up", steps[UP]);
    print_steps("down", steps[DOWN]);
    print_steps("right", steps[RIGHT]);
    print_steps("left", steps[LEFT]);

    return 0;
}

