#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int results[50000];
int n;

int dfs(int root, vector<vector<int> > graph) {
  if(results[root]) return results[root];
  results[root] = 1;
  int max_count = 0;

  for(int i = 0;i < n;i++) {
    if(graph[root][i]) {
      int count = dfs(i, graph);
      if(max_count < count) {
        max_count = count;
      }
    }
  }

  return results[root] = max_count + 1;
}

int main() {
  int t;
  int max_count, ans;

  cin >> t;
  for(int i = 0;i < t;i++) {
    ans = max_count = 0;

    cin >> n;
    vector<vector<int> > graph(n, vector<int>(n, 0));
    for(int j = 0;j < n;j++) {
      int u, v;
      cin >> u >> v;
      graph[u - 1][v - 1] = 1;
    }

    for(int j = 0;j < n;j++) {
      memset(results, 0, sizeof(results));
      int count = dfs(j, graph);
      if(max_count < count) {
        max_count = count;
        ans = j;
      }
    }

    cout << "Case " << i + 1 << ": " << ans + 1 << endl;
  }

  return 0;
}
