#include <stdio.h>

int main() {
  int t, n, c;
  int max_speed;
  int i, j;

  scanf("%d", &t);
  for(i = 0;i < t;i++) {
    max_speed = -1;
    scanf("%d", &n);

    for(j = 0;j < n;j++) {
      scanf("%d", &c);
      if (max_speed < c)
        max_speed = c;
    }

    printf("Case %d: %d\n", i + 1, max_speed);
  }

  return 0;
}
