#include <iostream>

using namespace std;

int main() {
  int b, s;
  int assessments[20001], assessment;

  cin >> b;
  for(int j = 0;j < b;j++) {
    cin >> s;
    assessments[0] = 0;
    cin >> assessments[1];
    for(int i = 2;i < s;i++) {
      cin >> assessments[i];
    }

    int sum = 0, ans = -1;
    int end, start, prev_start;
    start = prev_start = 0;
    int max_distance = 0;
    for(int i = 1;i < s;i++) {
      sum += assessments[i];
      if(sum > ans) {
        ans = sum;
        prev_start = start;
        end = i;
        max_distance = i - start;
      } else if(sum == ans) {
        int tmp_start = start;
        int tmp_end = i;
        if(start > tmp_end)
          tmp_start = prev_start;

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
