#include <stdio.h>
int INF = 200 * 10000 + 1;

int main() {
  int n_participants, budget, n_hotels, n_weeks, price, n_beds;
  int lowest_cost;
  int i, j, k;

  while(scanf("%d %d %d %d", &n_participants, &budget, &n_hotels, &n_weeks) == 4) {
    lowest_cost = INF;
    for(i = 0;i < n_hotels;i++) {
      scanf("%d", &price);

      for(j = 0;j < n_weeks;j++) {
        scanf("%d", &n_beds);
        if (n_beds < n_participants)
          continue;
        else
          if (lowest_cost > price * n_participants)
            lowest_cost = price * n_participants;
      }
    }

    if (lowest_cost > budget)
      printf("stay home");
    else
      printf("%d", lowest_cost);
    printf("\n");
  }

  return 0;
}
