#include <iostream>

using namespace std;

int solve(char *s, int i, int line_length) {
  int j;

  for(j = 1;j < line_length / i;j++) {
    for(int k = 0;k < i;k++) {
      if(*(s + k) != *(s + (i * j + k))) {
        return -1;
      }
    }
  }

  return j;
}

int main() {
  string line;
  int result;

  cin >> line;
  while(line[0] != '.') {
    int line_length = line.length();
    for(int i = 1;i <= line_length;i++) {
      if(line_length % i == 0) {
        if((result = solve(&line[0], i, line_length)) != -1) {
          cout << result << endl;
          break;
        }
      }
    }

    cin >> line;
  }

  return 0;
}
