#include <stdio.h>

int main() {
  int n, i;
  int salaries[3];

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    scanf("%d %d %d", &salaries[0], &salaries[1], &salaries[2]);
    printf("Case %d: ", i + 1);

    if (salaries[0] > salaries[1]) {
      if (salaries[1] > salaries[2]) {
        printf("%d", salaries[1]);
      } else if (salaries[0] > salaries[2]) {
        printf("%d", salaries[2]);
      } else {
        printf("%d", salaries[0]);
      }
    } else if (salaries[0] > salaries[2]) {
      printf("%d", salaries[0]);
    } else if (salaries[1] > salaries[2]) {
      printf("%d", salaries[2]);
    } else {
      printf("%d", salaries[1]);
    }

    printf("\n");
  }

  return 0;
}
