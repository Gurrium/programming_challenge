#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

tuple<int, int, int> solve(int A, int B, int C) {
  int c = sqrt(C) + 1;
  for(int z = -c;z < c; z++) {
    for(int y = -c; y < c; y++) {
      if(z == y) break;
      for(int x = -c; x < c; x++) {
        if(z == x || y == x) break;
        int a = x + y + z;
        int b = x * y * z;
        int c = pow(x, 2) + pow(y, 2) + pow(z, 2);
        if(a == A && b == B && c == C)
          return make_tuple(x, y, z);
      }
    }
  }

  return make_tuple(-10001, 0, 0);
}

int main() {
  int n;

  cin >> n;
  while(n--) {
    int A, B, C;
    cin >> A >> B >> C;
    auto results = solve(A, B, C);
    if(get<0>(results) == -10001)
      cout << "No solution.";
    else
      cout << get<0>(results) << " " << get<1>(results) << " " << get<2>(results);
    cout << endl;
  }

  return 0;
}
