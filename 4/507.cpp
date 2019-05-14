#include <iostream>

using namespace std;

int main() {
  int b, s;
  int assessments[20001], assessment;

  cin >> b;
  for(int j = 0;j < b;j++) {
    cout << endl << j + 1 << endl; // debug
    cin >> s;
    assessments[0] = 0;
    cin >> assessments[1];
    for(int i = 2;i < s;i++) {
      cin >> assessments[i];
      cout << "input[" << i << "] " << assessments[i] << endl; // debug
    }

    int sum = 0, ans = -1;
    int end, start, prev_start;
    start = prev_start = 0;
    int max_distance = 0;
    for(int i = 1;i < s;i++) {
      sum += assessments[i];
      printf("%d sum: %d, ans: %d, start: %d, prev_start: %d, end: %d, max_distance: %d\n", i, sum, ans, start, prev_start, end, max_distance); // debug
      if(sum > ans) {
        cout << "more" << endl; // debug
        ans = sum;
        prev_start = start;
        end = i;
        max_distance = i - start;
      } else if(sum == ans) {
        cout << "eql" << endl; // debug
        int tmp_start = start;
        int tmp_end = i;
        if(start > tmp_end)
          tmp_start = prev_start;

        printf("tmp_end: %d, tmp_start: %d, max_distance: %d\n", tmp_end, tmp_start, max_distance); // debug
        if((tmp_end - tmp_start) > max_distance) {
          prev_start = start;
          end = i;
        }
      }

      if(sum < 0) {
        start = i;
        sum = 0;
      }
    }
    if(start > end)
      start = prev_start;

    if(ans == -1)
      cout << "Route " << j + 1 << " has no nice parts";
    else
      cout << "The nicest part of route " << j + 1 << " is between stops " << start + 1 << " and " << end + 1;
    cout << endl;
  }

  return 0;
}
