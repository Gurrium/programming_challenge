#include <iostream>
// #include <cmath>

using namespace std;

unsigned long long int results[26][151];

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  return (a == 0 ? b : gcd(b % a, a));
}

unsigned long long int pow(unsigned long long int base, unsigned long long int exp) {
  unsigned long long int result = 1;
  for(int i = 0;i < exp;i++) {
    result = result * base;
  }

  return result;
}

unsigned long long int count(int dice_left, int score_left) {
  if(score_left <= 0){
    if(dice_left == 0) {
      return 1;
    } else {
      return pow(6, dice_left);
    }
  }
  if(score_left <= dice_left) {
    return pow(6, dice_left);
  }
  if(dice_left == 0) {
    return 0;
  }
  if(results[dice_left][score_left] != -1) {
    return results[dice_left][score_left];
  }

  unsigned long long sum = 0;
  for(int i = 0;i < 6;i++) {
    sum += count(dice_left - 1, score_left - (i + 1));
  }

  return results[dice_left][score_left] = sum;
}

int main() {
  int n, x;
  unsigned long long int result, gcdd, poww, denominator, numerator;

  for(int i = 0;i < 26;i++) {
    for(int j = 0;j < 151;j++) {
      results[i][j] = -1;
    }
  }
  cin >> n >> x;
  while(n != 0) {
    if(x == 0 || n >= x) {
      cout << 1 << endl;
      cin >> n >> x;
      continue;
    }
    result = count(n, x);
    poww = pow(6, n);
    gcdd = gcd(poww, result);
    denominator = poww / gcdd;
    numerator = result / gcdd;

    if(numerator == 1 && denominator == 1) {
      cout << 1 << endl;
    } else if(numerator == 0) {
      cout << 0 << endl;
    } else {
      cout << result / gcdd << '/' << poww / gcdd << endl;
    }

    cin >> n >> x;
  }
  return 0;
}
