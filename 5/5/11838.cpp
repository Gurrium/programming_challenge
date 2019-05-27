#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > intersection;
vector<bool> visited;

void dfs(int from) {
  if(visited[from]) return;
  visited[from] = true;
  for(const auto& to : intersection[from]) {
    dfs(to);
  }
}

int main() {
  int n, m;

  cin >> n >> m;
  while(n != 0) {
    if(n == 2) {
      cout << 1 << endl;
      cin >> n >> m;
      continue;
    }

    intersection.clear();
    while(m--) {
      int from, to, p;
      cin >> from >> to >> p;
      from--;
      to--;
      if(p == 2) {
        intersection[from].push_back(to);
        intersection[to].push_back(from);
      } else {
        intersection[from].push_back(to);
      }
    }

    bool result = true;
    for(int i = 0;i < n;i++) {
      visited.assign(n, false);
      dfs(i);
      for(const auto& v : visited) {
        if(!(result &= v)) {
          break;
        }
      }
      if(!result) break;
    }
    result = result ? 1 : 0;
    cout << result << endl;

    cin >> n >> m;
  }
}
