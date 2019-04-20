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

  for(i = 0;i < '~';i++)
    cost[i] = 0;

  scanf("%d", &n);
  // while(1) {
  for(i = 0;i < n;i++){
    totalCost = 0;
    scanf("%d%*c", &k);
    for(j = 0;j < k;j++) {
      scanf("%c%*[^0-9]", &c);
      scanf("%d%*[^\n]%*[\n]", &cost[c - 1]);
      printf("%c(%d): %d\n", c, c, cost[c - 1]);
    }

    scanf("%d%*c", &m);
    for(j = 0;j < m;j++) {
      getline(&line, &bufsize, stdin);
      // printf("%s\n", line);
      for(l = 0;line[l] != '\n';l++) {
        totalCost += cost[line[l] - 1];
        // printf("%c(%d): %d\n", line[l], line[l], cost[line[l] - 1]);
      }
    }

    printf("%d.%02d$\n", totalCost / 100, totalCost - (totalCost / 100 * 100));
  }
}
