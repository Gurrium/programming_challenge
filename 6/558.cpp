#include <iostream>
#include <vector>
#define INF 1000000

using namespace std;

void dfs(int node, double current_time) {

}

int main() {
  int c, n, m, from, to, time;
  vector<int> dist;

  cin >> c;
  for(int i = 0;i < c;i++) {
    cin >> n >> m;
    vector<vector<pair<int, int> > > adj_list(n);
    dist.assign(n, INF);

    for(int j = 0;j < m;j++) {
      cin >> from >> to >> time;
      adj_list[from].push_back(make_pair(to, time));
    }

    dist[0] = 0;
    for(int j = 0;j < n - 1;j++) {
      for(int k = 0;k < n;k++) {
        for(int l = 0;l < adj_list[k].size();l++) {
          to = adj_list[k][l].first;
          dist[to] = min(dist[to], dist[k] + adj_list[k][l].second);
        }
      }
    }

    bool is_possible = false;
    for(int k = 0;k < n;k++) {
      for(int l = 0;l < adj_list[k].size();l++) {
        to = adj_list[k][l].first;
        if(dist[to] > dist[k] + adj_list[k][l].second) {
          is_possible = true;
          break;
        }
      }
      if(is_possible) break;
    }

    if(is_possible) {
      cout << "possible";
    } else {
      cout << "not possible";
    }
    cout << endl;

  }

  return 0;
}
