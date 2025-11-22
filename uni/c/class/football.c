#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

typedef struct {
    int* indexes;
    int capacity;
    int len;
} Result;

void append_idx(Result* r, int idx) {
    r->len++;
    if (r->len > r->capacity) {
        // error
    }
    r->indexes[r->len] = idx;
}

// caller owns memory
Result new_result(int size) {
    Result r = {
        .indexes = (int*)malloc(sizeof(int) * size),
        .capacity = size,
        .len = 0,
    };
    return r;
}

void deinit_result(Result* r) {
    free(r->indexes);
    r->indexes = NULL;
    r->capacity = 0;
    r->len = 0;
}

typedef struct {
    int age;
    int goals;
    int height;
    int match_count;
    int number;
} Player;

Player new_player() {
    Player p = {
        .age = rand_int(16, 40),
        .goals = rand_int(0, 10),
        .height = rand_int(170, 220),
        .match_count = rand_int(0, 200),
        .number = rand_int(0, 99),
    };
    return p;
}

void print_player(Player p) {
    printf("age=%d, ", p.age);
    printf("goals=%d, ", p.goals);
    printf("height=%d, ", p.height);
    printf("matches=%d, ", p.match_count);
    printf("number=%d\n", p.number);
}

typedef struct {
    Player* players;
    int size;
} Team;

void deinit_players(Player* p) {
    free(p);
    p = NULL;
}

Team new_team() {
    Team t;
    printf("Team size: ");
    scanf("%d", &t.size);
    t.players = (Player*)malloc(sizeof(Player)*t.size);
    for (int i = 0; i < t.size; i++)
        t.players[i] = new_player();

    return t;
}

void deinit_team(Team *t) {
    deinit_players(t->players);
}

// filters t->players indexes into Result via gate_f
// Player is included if gate_f returns true
//
// caller owns Result's memory
Result filter(Team *t, int (*gate_f)(Player)) {
    Result res = new_result(t->size);
    for (int i = 0; i < t->size; i++)
        if (gate_f(t->players[i]))
            append_idx(&res, i);
    return res;
}

int match_gate(Player p) {
    return p.match_count >= 20;
}

int map(Team *t, int (*f)(int, Player)) {
    int res = 0;
    for (int i = 0; i < t->size; i++)
        res = f(res, t->players[i]);
    return res;
}

int sum_age(int sum, Player p) {
    return sum + p.age;
}

int pick(Team *t, int (*cmp)(Player, Player)) {
    int idx = -1;
    for (int i = 0; i < t->size; i++)
        if (idx == -1 || cmp(t->players[idx], t->players[i]))
            idx = i;
    return idx;
}

// Sorts players of t in a new array
//
// Caller owns memory of sorted array
Player* sort(Team* t, int (*cmp)(Player, Player)) {
    Player* sorted = (Player*)malloc(sizeof(Player) * t->size);
    Player temp;

    for (int i = 0; i < t->size; i++) {
        sorted[i] = t->players[i];
    }

    for (int i = 0; i < t->size; i++) {
        for (int j = i + 1; j < t->size; j++)
            if (cmp(sorted[i], sorted[j])) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
    }

    return sorted;
}

int cmp_oldest(Player p1, Player p2) {
    return p2.age > p1.age;
}

int cmp_most_goals(Player p1, Player p2) {
    return p2.goals > p1.goals;
}

int cmp_most_goals_under_25(Player p1, Player p2) {
    return p2.age < 25 && p2.goals > p1.goals;
}

int cmp_tallest(Player p1, Player p2) {
    return p2.height > p1.height;
}

int main() {
    srand(time(NULL));
    Team team = new_team();

    for (int i = 0; i < team.size; i++)
        print_player(team.players[i]);

    int target;
    printf("Will look for player number: ");
    scanf("%d", &target);

    printf("Oldest: %d\n", pick(&team, cmp_oldest));
    printf("Most goals: %d\n", pick(&team, cmp_most_goals));

    for (int i = 0; i < team.size; i++)
        if (team.players[i].number == target) {
            printf("Found target: %d\n", i);
            print_player(team.players[i]);
            break;
        }

    Result res = filter(&team, match_gate);
    printf("At least 20 matches: %d\n", res.len);
    deinit_result(&res);

    int age_sum = map(&team, sum_age);
    printf("Avg age: %.2f\n", (float)age_sum / team.size);

    printf("Most goals under 25: %d\n", pick(&team, cmp_most_goals_under_25));

    Player* height_sorted = sort(&team, cmp_tallest);
    printf("Sorted:\n");
    for (int i = 0; i < team.size; i++)
        print_player(height_sorted[i]);
    deinit_players(height_sorted);

    deinit_team(&team);
    return 0;
}
