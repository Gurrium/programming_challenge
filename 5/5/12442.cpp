#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> results, graph;
vector<bool> visited;
int n;

int dfs(int node) {
  results[node] = 1;
  visited[node] = true;
  if(graph[node] != -1 && !visited[graph[node]]) {
    results[node] += dfs(graph[node]);
  }
  visited[node] = false;

  return results[node];
}

int main() {
  int t;
  int max_count, ans;

  cin >> t;
  for(int i = 0;i < t;i++) {
    ans = max_count = 0;

    cin >> n;
    graph.assign(n, -1);
    results.assign(n, -1);
    visited.assign(n, false);
    for(int j = 0;j < n;j++) {
      int u, v;
      cin >> u >> v;
      graph[u - 1] = v - 1;
    }

    for(int j = 0;j < n;j++) {
      if(results[j] == -1) {
        int count = dfs(j);
        if(max_count < count) {
          max_count = count;
          ans = j;
        }
      }
    }

    cout << "Case " << i + 1 << ": " << ans + 1 << endl;
  }

  return 0;
}
