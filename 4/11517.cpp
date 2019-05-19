#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

#define INF 100000

using namespace std;

int main() {
  int t, price, n, coin;
  vector<int> coins;

  cin >> t;
  for(int i = 0;i < t;i++) {
    coins.clear();

    cin >> price >> n;
    for(int j = 0;j < n;j++) {
      cin >> coin;
      coins.push_back(coin);
    }

    int amount[20000];
    memset(amount, -1, sizeof(amount));
    amount[0] = 0;

    for(int k = 0;k < coins.size();k++) {
      for(int l = 10000;l > 0;l--) {
        if(amount[l] != -1) {
          if(amount[l + coins[k]] != -1) {
            amount[l + coins[k]] = min(amount[l] + 1, amount[l + coins[k]]);
          } else {
            amount[l + coins[k]] = amount[l] + 1;
          }
        }
      }
      amount[coins[k]] = 1;
    }

    int k = price;
    while(amount[k] == -1) {
      k++;
    }
    cout << k << ' ' << amount[k] << endl;
  }

  return 0;
}
