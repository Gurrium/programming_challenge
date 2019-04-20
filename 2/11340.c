#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, k, m;
  int totalCost;
  int i, j, l;
  char c;
  int cost['~'];
  char *line;
  size_t bufsize = 10000;
  line = (char *)malloc(bufsize * sizeof(char));

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    for(j = 0;j < '~';j++)
      cost[j] = 0;

    totalCost = 0;
    scanf("%d%*c", &k);
    for(j = 0;j < k;j++) {
      scanf("%c%*[ ]", &c);
      scanf("%d", &cost[c - 1]);

      while(getchar() != '\n');
    }

    scanf("%d%*c", &m);
    for(j = 0;j < m;j++) {
      getline(&line, &bufsize, stdin);
      for(l = 0;line[l] != '\n';l++) {
        totalCost += cost[line[l] - 1];
      }
    }

    printf("%d.%02d$\n", totalCost / 100, totalCost - (totalCost / 100 * 100));
  }
}
