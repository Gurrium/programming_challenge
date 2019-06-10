#include <iostream>
#include <cstring>
#define ulli unsigned long long int

ulli results[1000005];

using namespace std;

ulli solve(unsigned long int n) {
  if(results[n] != -1) return results[n];

  if(n % 2 == 0) {
    return results[n] = solve(n - 1) + ((n / 2) - 1) * (n - 2) / 2;
  } else {
    return results[n] = solve(n - 1) + ((n / 2) - 1) * (n - 1) / 2;
  }
}

int main() {
  unsigned long int n;

  memset(results, -1, sizeof(results));
  results[3] = 0;

  cin >> n;
  while(n >= 3) {
    cout << solve(n) << endl;

    cin >> n;
  }

  return 0;
}
