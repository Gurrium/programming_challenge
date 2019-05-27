#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<int> > neighbors;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;
map<int, vector<int> > articulate_station;
vector<bool> visited;
int iteration_counter, children_counter;

vector<int> pigeon_values;

void dfs(int station) {
  if(visited[station]) return;
  visited[station] = true;

  int size = neighbors[station].size();
  for(int i = 0;i < size;i++) {
    dfs(neighbors[station][i]);
  }
}

void tarjan(int station) {
  dfs_num[station] = dfs_low[station] = iteration_counter++;

  int size = neighbors[station].size();
  for(int i = 0;i < size;i++) {
    int direction = neighbors[station][i];

    if(dfs_num[direction] == -1) {
      dfs_parent[direction] = station;

      tarjan(direction);
      if(dfs_low[direction] >= dfs_num[station]) {
        articulation_vertex[station] = true;

        // int station_count = neighbors.size();
        // int pigeon_value = 0;
        // visited.assign(station_count, false);
        // visited[station] = true;
        // for(int j = 0;j < station_count;j++) {
        //   if(!visited[j]) {
        //     dfs(j);
        //     pigeon_value++;
        //   }
        // }
        // articulate_station[pigeon_value].push_back(station);
        pigeon_values[station]++;
      }
      dfs_low[station] = min(dfs_low[station], dfs_low[direction]);
    } else if(direction != dfs_parent[station]) {
      dfs_low[station] = min(dfs_low[station], dfs_num[direction]);
    }
  }
}

struct cmp
{
  template<class T>
  bool operator()(T const &a, T const &b) const { return a > b; }
};

int main() {
  int n, m;
  int x, y;

  cin >> n >> m;
  while(n + m != 0) {
    iteration_counter = 0;
    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    dfs_parent.assign(n, 0);
    articulation_vertex.assign(n, false);
    pigeon_values.assign(n, 1);
    articulate_station.clear();
    neighbors.clear();

    cin >> x >> y;
    while(x > -1) {
      neighbors[x].push_back(y);
      neighbors[y].push_back(x);

      cin >> x >> y;
    }

    tarjan(0);
    bool flag = false;

    pigeon_values[0]--;
    articulate_station.clear();
    for(int j = 0;j < n;j++) {
      articulate_station[pigeon_values[j]].push_back(j);
    }
    vector<int> v;
    for(map<int, vector<int> >::iterator i = articulate_station.begin();i != articulate_station.end();i++) {
      v.push_back(i->first);
    }
    sort(v.begin(), v.end(), cmp());
    for(const auto& key : v) {
      vector<int> stations = articulate_station[key];
      sort(stations.begin(), stations.end());
      auto last = unique(stations.begin(), stations.end());
      stations.erase(last, stations.end());
      for(const auto& station : stations) {
        cout << station << ' ' << key << endl;
        if(--m == 0) {
          flag = true;
          break;
        }
      }
      if(flag) break;
    }

    articulation_vertex[0] = false;
    if(!flag) {
      for(int i = 0;i < n;i++) {
        if(!articulation_vertex[i]) {
          cout << i << ' ' << neighbors[i].size() << endl;
          if(--m == 0) {
            flag = true;
            break;
          }
        }
      }
    }

    cout << endl;
    cin >> n >> m;
  }
}
