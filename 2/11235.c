#include <stdio.h>

int main() {
  int n, q, start, end, max, result, current;
  int numbers[100000];
  int results[100000];
  int i, j;

  scanf("%d", &n);
  while(n != 0) {
    scanf("%d", &q);
    for(i = 0;i < n;i++)
      scanf("%d", &numbers[i]);

    for(i = 0;i < q;i++) {
      result = max = 0;
      scanf("%d %d", &start, &end);

      current = numbers[start - 1];
      for(j = start - 1;j < end;j++) {
        if(current == numbers[j])
          result++;
        else {
          current = numbers[j];
          result = 1;
        }

        if(max < result) max = result;
      }

      printf("%d\n", max);
    }

    scanf("%d", &n);
  }
  return 0;
}
