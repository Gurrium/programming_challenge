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
      printf("return %d\n", 1); // debug
      return 1;
    } else {
      printf("return %llu\n", pow(6, dice_left)); // debug
      return pow(6, dice_left);
    }
  }
  if(score_left <= dice_left) {
    printf("return %llu\n", pow(6, dice_left)); // debug
    return pow(6, dice_left);
  }
  if(dice_left == 0) {
    printf("return %d\n",  0); // debug
    return 0;
  }
  if(results[dice_left][score_left] != -1) {
    printf("return %llu\n",  results[dice_left][score_left]); // debug
    return results[dice_left][score_left];
  }

  unsigned long long sum = 0;
  for(int i = 0;i < 6;i++) {
    printf("calling dice_left: %d, score_left: %d\n", dice_left - 1, score_left - (i + 1)); // debug
    sum += count(dice_left - 1, score_left - (i + 1));
  }

  printf("return %llu\n",  sum); // debug
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
    printf("n: %d, x: %d\n", n, x); // debug
    result = count(n, x);
    cout << "result: " << result << endl; // debug
    poww = pow(6, n);
    cout << "poww: " << poww << endl; // debug
    gcdd = gcd(poww, result);
    cout << "gcdd: " << gcdd << endl; // debug
    denominator = poww / gcdd;
    cout << "denominator: " << denominator << endl; // debug
    numerator = result / gcdd;
    cout << "numerator: " << numerator << endl; // debug

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
