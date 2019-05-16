#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  int m, n, p, f;
  int price, index;
  vector<int> item;
  vector<vector<int> > items;

  while(cin >> m) {
    items.clear();

    cin >> n;
    for(int i = 0;i < n;i++) {
      cin >> price >> index;
      item.clear();
      item.push_back(price);
      item.push_back(index);
      items.push_back(item);
    }

    int N_MAX = 10000 + 200 + 1;
    int index_sum[N_MAX];
    memset(index_sum, -1, sizeof(index_sum));
    index_sum[0] = 0;

    for(int i = 0;i < n;i++) {
      for(int j = m + 200;j > 0;j--) {
        if(index_sum[j] != -1) {
          if(j + items[i][0] > m + 200) continue;
          index_sum[j + items[i][0]] = max(index_sum[j] + items[i][1], index_sum[j + items[i][0]]);
        }
      }
      index_sum[items[i][0]] = max(index_sum[items[i][0]], items[i][1]);
    }

    int i = m + 200;
    int max_indices = 0;
    while(i >= 0) {
      if(m < i && i <= 2000) {
        i--;
        continue;
      }
      if(index_sum[i] > max_indices) {
        max_indices = index_sum[i];
      }
      i--;
    }
    cout << max_indices << endl;
  }

  return 0;
}
