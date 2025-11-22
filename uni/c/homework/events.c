#include <stdio.h>

#define N 12

struct {
    char name[30];
    unsigned int y, m, d;
    unsigned int participants;
} typedef Event;

Event scanfNewEvent() {
    Event e;
    scanf("%s", e.name);
    scanf("%d", &e.y);
    scanf("%d", &e.m);
    scanf("%d", &e.d);
    scanf("%d", &e.participants);
    return e;
}

void printfEvent(Event e) {
    printf("%s: year: %u, month: %u, day: %u, participants: %u\n", e.name, e.y, e.m, e.d, e.participants);
}

int main() {
    Event events[N];
    for (int i = 0; i < N; i++)
        events[i] = scanfNewEvent();

    unsigned int jul_events = 0;
    int most_popular_idx = -1;
    printf("All events:\n");
    for (int i = 0; i < N; i++) {
        Event e = events[i];
        printfEvent(e);
        if (e.y == 2022 && e.m == 7)
            jul_events++;
        if (most_popular_idx == -1 || events[i].participants > events[most_popular_idx].participants)
            most_popular_idx = i;
    }

    printf("Events in 2022 july: %u\n\n", jul_events);
    printf("Event with the most participants: %s\n", events[most_popular_idx].name);
}
