#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ld(vector<int> lhs, vector<int> rhs) {
  int lhs_length = lhs.size() + 1;
  int rhs_length = rhs.size() + 1;
  int results[2][rhs_length];

  for(int i = 0;i < 2;i++) {
    results[i][0] = 0;
  }
  for(int j = 0;j < rhs_length;j++) {
    results[0][j] = 0;
  }

  int cost = 0;
  bool toggle = true;
  for(int i = 1;i < lhs_length;i++) {
    if(toggle) {
      for(int j = 1;j < rhs_length;j++) {
        cost = lhs[i - 1] == rhs[j - 1] ? 1 : 0;
        results[1][j] = max(results[0][j - 1] + cost,
                            max(results[0][j], results[1][j - 1]));
      }
    } else {
      for(int j = 1;j < rhs_length;j++) {
        cost = lhs[i - 1] == rhs[j - 1] ? 1 : 0;
        results[0][j] = max(results[1][j - 1] + cost,
                            max(results[1][j], results[0][j - 1]));
      }
    }
    toggle = !toggle;
  }

  if(toggle) {
    return results[0][rhs_length - 1];
  } else {
    return results[1][rhs_length - 1];
  }
}

int main() {
  int t, n, p, q;
  int key, counter = 0;
  vector<int> prince_v, princess_v;
  int *prince;

  cin >> t;
  for(int i = 0;i < t;i++) {
    prince_v.clear();
    princess_v.clear();

    cin >> n >> p >> q;
    prince = (int *)malloc(sizeof(int) * n * n + 1);

    for(int j = 0;j < p + 1;j++) {
      cin >> key;
      prince[key] = 1;
      prince_v.push_back(key);
    }

    for(int j = 0;j < q + 1;j++) {
      cin >> key;
      if(prince[key] == 1) {
        princess_v.push_back(key);
      }
    }

    int result = ld(prince_v, princess_v);
    cout << "Case " << ++counter << ": " << result << endl;
  }

  return 0;
}
