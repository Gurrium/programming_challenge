#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#define NODE_COUNT 10 + 26 + 2

using namespace std;

int main() {
  string line;
  map<char, map<char, int> > graph;
  map<char, map<char, int> > residual[NODE_COUNT][NODE_COUNT];

  while(getline(cin, line)) {
    graph.clear();
    while(line[0] != 0 && !cin.eof()) {
      graph['r'][line[0]] = atoi(&line[1]);

      for(char *c = &line[3];*c != ';';c++) {
        graph[line[0]][*c] = 1;
        graph[*c]['e'] = 1;
      }

      getline(cin, line);
    }

    for(const auto& [key, destinations] : graph) {
      for(const auto& [destination, cost] : destinations) {
        residual[key][destination] = cost;
      }
    }

    int p;
    char parents[NODE_COUNT];
    char parent;
    int min_capacity;
    while(dfs(graph, parents)) {
      min_capacity = INT_MAX;
      for(char node = 'e';node != 's';node = parents[node]) {
        parent = parents[node];
        min_capacity = min(min_capacity, residual[parent][node]);
      }

      for(char node = 'e';node != 's';node = parents[node]) {
        parent = parents[node];
        residual[parent][node] -= min_capacity;
        residual[node][parent] += min_capacity;
      }
    }

    bool done = false;
    for(const auto& [key, destinations] : residual) {
      if('0' <= key && key <= '9') {
        for(const auto& [destination, cost] : destinations) {
          if(cost != 0) {
            cout << destination;
            done = true;
          }
        }
        if(!done) {
          cout << '_';
          done = false;
        }
      }
    }

    if(cin.eof()) {
      break;
    }
  }

  return 0;
}
