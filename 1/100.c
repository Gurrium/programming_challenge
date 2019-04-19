#include <stdio.h>
int LENGTH = 1000000;

int main() {
  int i, j, tmp;
  int m, n;
  int max_cycle_length, cycle_length;

  int results[LENGTH];
  for(i = 0;i < LENGTH;i++)
    results[i] = 0;
  results[1] = 1;

  while(scanf("%d %d", &i, &j) == 2) {
    printf("%d %d ", i, j);
    max_cycle_length = 0;

    if (i > j) {
      tmp = i;
      i = j;
      j = tmp;
    }

    for(m = i;m < j + 1;m++) {
      cycle_length = 1;
      n = m;

      while(n != 1) {
        if (n < LENGTH)
          if (results[n]) {
            cycle_length = cycle_length + results[n] - 1;
            break;
          }

        cycle_length++;

        if (n % 2)
          n = 3 * n + 1;
        else
          n /= 2;
      }

      if (n < LENGTH)
        results[m] = cycle_length;
      if(max_cycle_length < cycle_length)
        max_cycle_length = cycle_length;
    }

    printf("%d\n", max_cycle_length);
  }

  return 0;
}
