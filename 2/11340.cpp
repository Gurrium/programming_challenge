#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n, k, m;
  double totalCost;

  cin >> n;
  for(int i = 0;i < n;i++) {
    totalCost = 0.0;
    map<char, double> costs;

    cin >> k;
    for(int j = 0;j < k;j++) {
      char c;
      double cost;
      cin >> c >> cost;
      costs[c] = cost;
    }

    cin >> m;
    cin.ignore();
    for(int j = 0;j < m;j++) {
      string line;
      getline(cin, line);

      for(int l = 0;l < line.size();l++) {
        totalCost += costs[line[l]];
      }
    }

    printf("%.2f$\n", totalCost / 100);
  }

   return 0;
}
