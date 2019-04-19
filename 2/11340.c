#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, k, m, cost['~'], totalCost = 0;
  int i, j, l;
  char s[10000];

  for(i = ' ';i <= '~';i++) {
    cost[i] = 0;
  }

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    scanf("%d", &k);
    for(j = 0;j < k;j++) {
      scanf("%s", s);
      scanf("%d", &cost[s[0]]);
    }

    scanf("%s", s);
    printf("%s\n", s); // 表示される

    scanf("%d", &m);
    for(j = 0;j < m;j++) {
      printf("%s\n", s); // 表示される
      scanf("%s", s);
      printf("%s", s); // abort
      for(l = 0;s[l] != '\0';l++) {
        totalCost += cost[s[l]];
      }
    }

    printf("%d.%02d$", totalCost / 100, totalCost - (totalCost / 100));
  }

  return 0;
}
