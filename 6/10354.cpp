#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#define INF 10000

using namespace std;

vector<bool> visited;

void dfs(vector<vector<int> > graph, int node) {
  if(visited[node]) return;
  visited[node] = true;

  int size = graph[node].size();
  for(int i = 0;i < size;i++) {
    dfs(graph, graph[node][i]);
  }
}

int main() {
  int p, r, bh, of, yh, m;
  int from, to, cost;
  string line;

  while(cin >> p) {
    cin >> r >> bh >> of >> yh >> m;
    bh--;of--;yh--;m--;

    int bweight[p][p], yweight[p][p];
    for(int i = 0;i < p;i++) {
      for(int j = 0;j < p;j++) {
        bweight[i][j] = yweight[i][j] = INF;
      }
      bweight[i][i] = yweight[i][i] = 0;
    }
    vector<vector<int> > parents(p);
    int dist[p];
    fill(dist, dist + p, INF);
    visited.assign(p, false);

    for(int i = 0;i < r;i++) {
      cin >> from >> to >> cost;
      from--;to--;
      bweight[from][to] = cost;
      bweight[to][from] = cost;
      yweight[from][to] = cost;
      yweight[to][from] = cost;
    }

    if(bh == m | bh == yh | of == m | of == yh) {
      cout << "MISSION IMPOSSIBLE." << endl;
      continue;
    }

    for(int j = 0;j < p;j++) {
      for(int k = 0;k < p;k++) {
        for(int l = 0;l < p;l++) {
          bweight[k][l] = min(bweight[k][l], bweight[k][j] + bweight[j][l]);
        }
      }
    }
    for(int j = 0;j < p;j++) {
      if(bweight[bh][of] == bweight[bh][j] + bweight[j][of])
        visited[j] = true;
    }
    if(visited[yh] | visited[m]) {
      cout << "MISSION IMPOSSIBLE." << endl;
      continue;
    }

    for(int j = 0;j < p;j++) {
      if(visited[j]) {
        continue;
      }
      for(int k = 0;k < p;k++) {
        if(visited[k]) {
          continue;
        }
        for(int l = 0;l < p;l++) {
          if(visited[l]) {
            continue;
          }
          yweight[k][l] = min(yweight[k][l], yweight[k][j] + yweight[j][l]);
        }
      }
    }

    if(yweight[yh][m] != INF) {
      cout << yweight[yh][m];
    } else {
      cout << "MISSION IMPOSSIBLE.";
    }
    cout << endl;
  }
}
