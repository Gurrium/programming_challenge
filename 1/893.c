#include <stdio.h>

int days_of_year(int year) {

}

int days_of_month(int year, int month) {

}

int main() {
  int days, day, month, year;

  scanf("%d %d %d %d", &days, &day, &month, &year);
  while(days + day + month + year != 0) {
    while(days > days_of_month(year, month)) {
      while(days > days_of_year(year)) {
        days -= days_of_year(year);
        year++;
      }

      days -= days_of_month(year, month);
      if (++month > 12) {
        month = 0;
      }
    }

    day += days;

    printf("%d %d %d\n", day, month, year);

    scanf("%d %d %d %d", &days, &day, &month, &year);
  }

  return 0;
}
