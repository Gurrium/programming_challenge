#include <iostream>
#include <cstring>

using namespace std;

int graph[100][100];
int n;

void dfs(int vertex, int except, int *visited) {
  if(visited[vertex]) return;
  visited[vertex] = 1;

  for(int i = 0;i < n;i++) {
    if(i == except) continue;
    if(graph[vertex][i]) dfs(i, except, visited);
  }
}

int main() {
  int t;
  int visited[100];
  int visited0[100];

  cin >> t;
  for(int i = 0;i < t;i++) {
    memset(graph, 0, sizeof(graph));
    memset(visited0, 0, sizeof(visited0));
    memset(visited, 0, sizeof(visited));

    cin >> n;
    for(int j = 0;j < n;j++) {
      for(int k = 0;k < n;k++) {
        cin >> graph[j][k];
      }
    }

    cout << "Case " << i + 1 << ':' << endl;
    dfs(0, -1, visited0);
    cout << '+';
    for(int l = 0;l < 2 * n - 1;l++) {
      cout << '-';
    }
    cout << '+' << endl;
    cout << '|';
    for(int m = 0;m < n;m++) {
      if(visited0[m]) {
        cout << 'Y';
      } else {
        cout << 'N';
      }
      cout << '|';
    }
    cout << endl;
    cout << '+';
    for(int l = 0;l < 2 * n - 1;l++) {
      cout << '-';
    }
    cout << '+' << endl;

    for(int l = 1;l < n;l++) {
      memset(visited, 0, sizeof(visited));
      dfs(0, l, visited);

      cout << '|';
      for(int m = 0;m < n;m++) {
        if(!visited[m]) {
          if(visited0[m]) {
            cout << 'Y';
          } else {
            cout << 'N';
          }
        } else {
          cout << 'N';
        }
        cout << '|';
      }
      cout << endl;
      cout << '+';
      for(int l = 0;l < 2 * n - 1;l++) {
        cout << '-';
      }
      cout << '+' << endl;
    }
  }
}
