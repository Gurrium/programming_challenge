#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <array>
#include <queue>
#include <map>

using namespace std;

class Node {
  public:
    vector<int> topo_out_nodes;
    vector<int> out_nodes;
    bool constrained;
    int in_degree;

    Node() {
      in_degree = 0;
      constrained = false;
    }
};

vector<bool> visited;
map<int, Node> variables;

void dfs(int key, vector<int> parents) {
  printf("key: %c \n", key); // debug
  for(const auto& parent : parents) { // debug
    printf("%c ", parent); // debug
  } // debug
  cout << endl; // debug
  if(visited[key]) return;
  visited[key] = true;
  bool results = true;
  for(const auto& node : variables[key].out_nodes) {
    results &= visited[node];
  }

  if(results) {
    int parent_size = parents.size();
    int i = 0;
    cout << endl << "result" << endl; // debug
    for(i = 0;i < parent_size;i++) {
      printf("%c ", parents[i]);
    }
    printf("%c\n", key);
    cout << endl << endl; // debug
  } else {
    parents.push_back(key);
    for(const auto& node : variables[key].out_nodes) {
      dfs(node, parents);
    }
  }
  visited[key] = false;
}


int main() {
  int t;
  char variable;
  vector<string> constraints;
  vector<array<int, 2> > edges;
  vector<int> toposort;
  vector<int> topo_root;
  string token;
  string line;
  char delim = ' ';

  cin >> t;
  for(int i = 0;i < t;i++) {
    getline(cin, line); // read return
    getline(cin, line); // read blank line
    constraints.clear();
    toposort.clear();
    edges.clear();
    variables.clear();
    visited.assign(26, false);
    Node node;

    getline(cin, line);
    for(char *ptr = &line[0];*ptr != '\0';ptr++) {
      if(*ptr == ' ') continue;
      Node node;
      variables[*ptr] = node;
      printf("got: %c(%d)\n", *ptr, *ptr); // debug
    }

    getline(cin, line);
    char *ptr = &line[0];
    while(*ptr != '\0') {
      array<int, 2> edge = { *ptr, *(ptr + 2 * sizeof(char)) };
      printf("from %c(%d) to %c(%d)\n", edge[0], edge[0], edge[1], edge[1]); // debug
      edges.push_back(edge);
      variables[edge[0]].out_nodes.push_back(*(ptr + 2 * sizeof(char)));
      variables[edge[1]].in_degree++;
      printf("in_degree of %c: %d\n", edge[1], variables[edge[1]].in_degree); // debug
      variables[edge[0]].constrained = true;
      variables[edge[1]].constrained = true;

      ptr += 3;
      if(*ptr == ' ') {
        ptr++;
      } else if(*ptr == '\0') {
        break;
      }
    }

    queue<int> Q;
    for(auto& [key, value] : variables) {
      if(!value.constrained) {
        for(auto& [kkey, vvalue] : variables) {
          if(kkey != key && vvalue.constrained) {
            vvalue.out_nodes.push_back(key);
          }
        }
      }
      if(value.in_degree == 0) {
        if(value.constrained) {
          Q.push(key);
          topo_root.push_back(key);
        } else {
          for(auto& [kkey, vvalue] : variables) {
            if(kkey != key) {
              value.out_nodes.push_back(kkey);
            }
          }
        }
      }
    }
    cout << "Q.size(): " << Q.size() << endl; // debug
    if(Q.size() == 0) {
      cout << "NO" << endl;
      break;
    }
    for(const auto& [key, value] : variables) { // debug
      printf("%c: ", key); // debug
      for(const auto& node : value.out_nodes) { // debug
        printf("%c ", node); // debug
      } // debug
      cout << endl; // debug
    } // debug

    while(Q.size() > 0) {
      int key = Q.front();
      Q.pop();
      toposort.push_back(key);
      for(auto const& direction : variables[key].out_nodes) {
        if(--variables[direction].in_degree == 0) {
          Q.push(direction);
        }
      }
    }

    vector<int> parents;
    dfs(toposort[0], parents);
    // for(auto const& [key, value] : variables) {
    //   parents.clear();
    //   if(!value.constrained) {
    //     parents.push_back(key);
    //     dfs(key, parents);
    //   }
    // }
  }

  return 0;
}
