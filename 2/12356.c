#include <stdio.h>

typedef struct {
  int right, left;
  int is_dead;
} soldier;

int right(soldier soldiers[], int index) {
  if(index == -1) return -1;

  int right;

  while(soldiers[index].is_dead && soldiers[index].right != -1)
    index = soldiers[index].right;

  if(!soldiers[index].is_dead)
    return index;
  else
    return -1;
}

int left(soldier soldiers[], int index) {
  if(index == -1) return -1;

  int left;

  while(soldiers[index].is_dead && soldiers[index].left != -1)
    index = soldiers[index].left;

  if(!soldiers[index].is_dead)
    return index;
  else
    return -1;
}

int main() {
  int s, b;
  int start, end;
  soldier soldiers[100001];
  int i;

  for(i = 0;i < 100001;i++) {
    soldiers[i].right = soldiers[i].left = -1;
    soldiers[i].is_dead = 1;
  }

  scanf("%d %d", &s, &b);
  while(s != 0 && b != 0) {
    soldiers[1].is_dead = 0;
    for(i = 2;i <= s;i++) {
      soldiers[i - 1].right = i;
      soldiers[i].left = i - 1;
      soldiers[i].is_dead = 0;
    }

    for(i = 0;i < b;i++) {
      scanf("%d %d", &start, &end);

      soldiers[start - 1].right = soldiers[start].right = soldiers[end].right;
      soldiers[end + 1].left = soldiers[end].left = soldiers[start].left;

      int left_index = left(soldiers, soldiers[start].left);
      if(left_index == -1)
        printf("*");
      else
        printf("%d", left_index);
      printf(" ");

      int right_index = right(soldiers, soldiers[end].right);
      if(right_index == -1)
        printf("*");
      else
        printf("%d", right_index);
      printf("\n");

      soldiers[start].is_dead = 1;
      soldiers[end].is_dead = 1;
    }

    printf("-\n");

    for(i = 1;i < 100001;i++)
      soldiers[i].right = soldiers[i].left = -1;

    scanf("%d %d", &s, &b);
  }

  return 0;
}
