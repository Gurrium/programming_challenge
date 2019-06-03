#include <iostream>
#include <vector>
#include <map>
#define INF 10000

using namespace std;

map<string, int> dictionary;
int dic_counter = 0;
vector<bool> visited;

int id(string name) {
  if(dictionary.find(name) == dictionary.end()) {
    return dictionary[name] = dic_counter++;
  } else {
    return dictionary[name];
  }
}

void dfs(int node, vector<vector<int> > graph) {
  if(visited[node]) {
    return;
  }
  visited[node] = true;

  int size = graph[node].size();
  for(int i = 0;i < size;i++) {
    dfs(graph[node][i], graph);
  }
}

int main() {
  int p, r;
  int counter = 1;

  cin >> p >> r;
  while(p + r != 0) {
    dic_counter = 0;
    dictionary.clear();
    visited.assign(p, false);
    int weight[p][p];
    for(int i = 0;i < p;i++) {
      for(int j = 0;j < p;j++) {
        weight[i][j] = INF;
      }
    }
    vector<vector<int> > graph(p);

    for(int i = 0;i < r;i++) {
      string from, to;
      int from_id, to_id;
      cin >> from >> to;
      from_id = id(from);
      to_id = id(to);
      graph[from_id].push_back(to_id);
      graph[to_id].push_back(from_id);
      weight[from_id][to_id] = weight[to_id][from_id] = 1;
    }

    bool flag = false;
    int size = graph.size();
    dfs(0, graph);
    for(int i = 0;i < p;i++) {
      if(!visited[i]) {
        printf("Network %d: DISCONNECTED\n\n", counter++);
        flag = true;
        break;
      }
    }
    if(flag){
      cin >> p >> r;
      continue;
    }
    for(int i = 0;i < p;i++) {
      weight[i][i] = 0;
    }

    for(int i = 0;i < p;i++) {
      for(int j = 0;j < p;j++) {
        for(int k = 0;k < p;k++) {
          weight[j][k] = min(weight[j][k], weight[j][i] + weight[i][k]);
        }
      }
    }

    int max_weight = 0;
    for(int i = 0;i < p;i++) {
      for(int j = 0;j < p;j++) {
        max_weight = max(weight[i][j], max_weight);
      }
    }

    printf("Network %d: %d\n\n", counter++, max_weight);

    cin >> p >> r;
  }

  return 0;
}
