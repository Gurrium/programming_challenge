#include <iostream>
#include <cmath>

double PI = 2 * acos(0.0);

using namespace std;

double circumcircle(double a, double b, double c) {
  double abc = a * b * c;
  double r = abc / sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c));
  return r * r * PI;
}

double heron(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double circle(double s, double a, double b, double c) {
  double r = 2 * s / (a + b + c);
  return r * r * PI;
}

int main() {
  double a, b, c;
  double r;
  double sunflower, violet, rose;
  while(cin >> a >> b >> c) {
    sunflower = circumcircle(a, b, c);
    violet = heron(a, b, c);
    rose = circle(violet, a, b, c);
    printf("%.4lf %.4lf %.4lf\n", sunflower - violet, violet - rose, rose);
  }

  return 0;
}
