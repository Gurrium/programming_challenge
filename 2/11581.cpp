#include <iostream>

using namespace std;

int g[3][3];
int h[3][3];

void f() {
  h[0][0] = g[0][1] + g[1][0];
  h[0][1] = g[0][0] + g[0][2] + g[1][1];
  h[0][2] = g[0][1] + g[1][2];
  h[1][0] = g[0][0] + g[1][1] + g[2][0];
  h[1][1] = g[0][1] + g[1][2] + g[2][1] + g[1][0];
  h[1][2] = g[0][2] + g[1][1] + g[2][2];
  h[2][0] = g[1][0] + g[2][1];
  h[2][1] = g[1][1] + g[2][2] + g[2][0];
  h[2][2] = g[1][2] + g[2][1];

  for(int i = 0;i < 3;i++)
    for(int j = 0;j < 3;j++)
      g[i][j] = h[i][j] % 2;
}

int isNotZero() {
  for(int i = 0;i < 3;i++)
    for(int j = 0;j < 3;j++)
      if(g[i][j] == 1) return 1;

  return 0;
}

int main() {
  int testCasesCount;
  cin >> testCasesCount;
  while(testCasesCount--) {
    int i = -1;
    cin.ignore();

    for(int i = 0;i < 3;i++) {
      int column;
      cin >> column;

      g[i][0] = column / 100;
      g[i][1] = column / 10 - (column / 100 * 10);
      g[i][2] = column - column / 10 * 10;
      cin.ignore();
    }

    while(isNotZero()) {
      i++;
      f();
    }

    cout << i << endl;
  }

  return 0;
}
