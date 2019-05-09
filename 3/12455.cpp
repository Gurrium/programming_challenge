#include <iostream>
#include <vector>

using namespace std;

int fill(vector<double> bars, int space, int index) {
  if(index < 0) return -1;

  for(int i = index;i >= 0;i--) {
    if(space - bars[i] == 0)
      return 1;
    else if(space - bars[i] > 0)
      if(fill(bars, space - bars[i], i - 1) == 1) return 1;

    if(space == 0)
      return 1;
    else if(space > 0)
      if(fill(bars, space, i - 1) == 1) return 1;
  }

  return -1;
}

int main() {
  int t, n, p, length;
  vector<double> bars;

  cin >> t;
  while(t--) {
    bars.clear();
    cin >> n >> p;
    while(p--) {
      cin >> length;
      if(!(length <= 0 || length > n))
        bars.push_back(length);
    }

    if(n == 0) {
      cout << "YES" << endl;
      continue;
    }

    int isSucceeded = 0;
    for(int i = bars.size() - 1;i >= 0;i--) {
      if(n - bars[i] == 0) {
        isSucceeded = 1;
        break;
      } else if(n - bars[i] > 0) {
        if(fill(bars, n - bars[i], i - 1) == 1) {
          isSucceeded = 1;
        }
      }

      if(n == 0) {
        isSucceeded = 1;
        break;
      } else if(n > 0) {
        if(fill(bars, n, i - 1) == 1) {
          isSucceeded = 1;
          break;
        }
      }
    }

    if(isSucceeded)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
