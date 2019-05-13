#include <iostream>
#include <vector>
#define INF 100000

using namespace std;

int n, m, c;
vector<int> ks;
vector< vector<int> > all_costs;
vector<vector<int> > results(201, vector<int>(20, -1));

int shop(int budget, int g) {
  if(budget < 0) return -INF;
  if(g == c) return m - budget;
  if(results[budget][g] != -1) return results[budget][g];

  int max = -INF - 1;
  int current_result;
  for(int i = 0;i < ks[g];i++) {
    current_result = shop(budget - all_costs[g][i], g + 1);
    if(current_result > max) max = current_result;
  }

  return results[budget][g] = max;
}

int main() {
  int k;
  int cost;
  vector<int> costs;

  cin >> n;
  for(int o = 0;o < n;o++) {
    for(int i = 0;i < results.size();i++) {
      fill_n(results[i].begin(), results[i].size(), -1);
    }
    all_costs.clear();
    ks.clear();
    int i = 0;

    cin >> m >> c;
    for(int p = 0;p < c;p++) {
      cin >> k;
      ks.push_back(k);
      for(int q = 0;q < k;q++) {
        cin >> cost;
        costs.push_back(cost);
      }
      all_costs.push_back(costs);
      costs.clear();
    }

    int result;
    if((result = shop(m, 0)) != -INF)
      cout << result;
    else
      cout << "no solution";
    cout << endl;
  }
}
