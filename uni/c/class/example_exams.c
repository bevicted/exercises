#include <stdio.h>

#define CAPACITY 20

struct {
  int day;
  int cost;
  int is_cash;
} typedef Purchase;

int main() {
  Purchase purchases[CAPACITY] = {
    {5, 7600, 0},
    {9, 21200, 0},
    {4, 4500, 1},
    {12, 1230, 1},
    {23, 21300, 0},
    {8, 32400, 1},
    {5, 8700, 1},
    {30, 10500, 1},
    {27, 4300, 0},
    {28, 1200, 0},
    {5, 1230, 1},
    {16, 25000, 0},
    {5, 4300, 0},
    {12, 6500, 1},
    {29, 12040, 0},
    {16, 22300, 1},
    {27, 4500, 0},
    {27, 10300, 1},
    {3, 20050, 0},
    {28, 1300, 1},
  };

  int sum = 0;
  int cashSum = 0;
  int cardSum = 0;
  int cardPaymentsAboveTenK = 0;
  int mostExpensiveIdx = 0;
  int mostExpensiveCashIdx = -1;

  for (int i = 0; i < CAPACITY; i++) {
    int cost = purchases[i].cost;

    sum += cost;
    if (cost > purchases[mostExpensiveIdx].cost)
      mostExpensiveIdx = i;

    if (purchases[i].is_cash) {
      cashSum += cost;

      if (mostExpensiveCashIdx == -1 || cost > purchases[mostExpensiveCashIdx].cost)
        mostExpensiveCashIdx = i;

      continue;
    }

    cardSum += cost;
    if (cost >= 10000) {
      cardPaymentsAboveTenK++;
    }
  }

  // 1
  printf("Total monthly cost: %d Social Credit\n", sum);

  // 2
  if (cashSum > cardSum)
    printf("Paid more in cash\n");
  else if (cardSum < cashSum)
    printf("Paid more with card\n");
  else
    printf("Paid the same amount in both cash and card\n");

  // 3
  printf("Card payments above 10k: %d\n", cardPaymentsAboveTenK);

  // 4
  printf("Most expensive purchase idx: %d\n", mostExpensiveIdx);

  // 5
  if (mostExpensiveCashIdx == -1)
    printf("There were no cash purchases\n");
  else
    printf("Most expensive cash purchase idx: %d\n", mostExpensiveCashIdx);

  // 6
  int purchaseDays[31] = {0};
  for (int i = 0; i < CAPACITY; i++) {
    purchaseDays[purchases[i].day - 1]++;
  }

  int uniqueDays = 0;
  for (int i = 0; i < 31; i++) {
    if ( purchaseDays[i] != 0)
      uniqueDays++;
  }

  printf("Unique days: %d\n", uniqueDays);
  printf("Empty days: %d\n", 31 - uniqueDays);

  return 0;
}
