#include <stdio.h>

typedef struct {
  int right, left;
} soldier;

int main() {
  int s, b;
  int start, end;
  soldier soldiers[100001];
  int i;

  for(i = 0;i < 100001;i++)
    soldiers[i].right = soldiers[i].left = -1;

  scanf("%d %d", &s, &b);
  while(s != 0 && b != 0) {
    for(i = 2;i <= s;i++) {
      soldiers[i - 1].right = i;
      soldiers[i].left = i - 1;
    }

    for(i = 0;i < b;i++) {
      scanf("%d %d", &start, &end);

      soldiers[soldiers[start].left].right = soldiers[end].right;
      soldiers[soldiers[end].right].left = soldiers[start].left;

      int left_index = soldiers[start].left;
      if(left_index == -1)
        printf("*");
      else
        printf("%d", left_index);
      printf(" ");

      int right_index = soldiers[end].right;
      if(right_index == -1)
        printf("*");
      else
        printf("%d", right_index);
      printf("\n");
    }

    printf("-\n");

    for(i = 1;i < 100001;i++)
      soldiers[i].right = soldiers[i].left = -1;

    scanf("%d %d", &s, &b);
  }

  return 0;
}
