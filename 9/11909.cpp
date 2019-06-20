#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double l, w, h, theta;
  double PI = 2 * acos(0.0);
  double threshold;
  double result;

  while(cin >> l >> w >> h >> theta) {
    threshold = atan(l / h);
    theta = theta * PI / 180;

    if(theta > PI / 2 - threshold) {
      result = w * h * h * tan(PI / 2 - theta) / 2;
    } else {
      result = l * w * (h - l * tan(theta) / 2);
    }
    printf("%.3lf mL\n", result);
  }

  return 0;
}
