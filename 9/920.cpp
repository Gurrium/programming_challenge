#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int, int>> peaks;

void solve() {
  double theta;
  double sum = 0.0;
  double x, y, result;
  int i, j;

  int length = peaks.size();
  for(i = length - 1;i > 0;) {
    for(j = i - 1;j > 0 && peaks[j].second < peaks[i].second;j--);
    if(peaks[j].second == peaks[i].second) {
      i = j;
      continue;
    }
    if(j == 0 && peaks[j].second <= peaks[i].second) {
      i = 0;
      continue;
    }

    y = (double)(peaks[j].second - peaks[j + 1].second);
    x = (double)(peaks[j + 1].first - peaks[j].first);
    theta = atan2(x, y);
    sum += (double)(peaks[j].second - peaks[i].second) / cos(theta);

    i = j;
  }

  printf("%.2f\n", sum);
}

int main() {
  int c, n;
  int x, y;

  cin >> c;
  for(int i = 0;i < c;i++) {
    peaks.clear();

    cin >> n;
    for(int j = 0;j < n;j++) {
      cin >> x >> y;
      peaks.push_back(make_pair(x, y));
    }
    sort(peaks.begin(), peaks.end());

    solve();
  }
}
