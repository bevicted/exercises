#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 14

int main() {
  float input, arr[INPUT_SIZE];

  scanf("%f", arr);
  int len = 1;

  for (int i = 1; i < INPUT_SIZE; i++) {
    scanf("%f", &input);
    if (input >= arr[len - 1]) {
      arr[len] = input;
      len++;
      continue;
    }

    for (int j = 0; j < len; j++) {
      if (input < arr[j]) {
        if (j < (INPUT_SIZE - 1))
          memmove(&arr[j + 1], &arr[j], (len - j) * sizeof(float));
        arr[j] = input;
        len++;
        break;
      }
    }
  }

  for (int i = 0; i < INPUT_SIZE; i++)
    printf("%f\n", arr[i]);

  return 0;
}
