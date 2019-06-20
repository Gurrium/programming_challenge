#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct segment {
  pair<int, int> start, end;
  int result = -1;
};
vector<struct segment> segments;
vector<pair<int, int> > sources;

bool sort_segments(const struct segment &lhs, const struct segment &rhs) {
  return lhs.start.second > rhs.start.second;
}

bool is_in_range(const pair<int, int> source, const struct segment seg) {
  if(seg.end.second > source.second) {
    return false;
  }

  int s, e;
  double a, y;
  if(seg.start.first > seg.end.first) {
    s = seg.end.first;
    e = seg.start.first;
    a = (double)(seg.start.second - seg.end.second) / (double)(e - s);

    if(!(s <= source.first && source.first <= e)) {
      return false;
    }
    y = (double)(source.first - s) * a;
    return (source.second - seg.end.second) - y < 0 ? false : true;
  } else {
    s = seg.start.first;
    e = seg.end.first;
    a = (double)(seg.end.second - seg.start.second) / (double)(e - s);

    if(!(s <= source.first && source.first <= e)) {
      return false;
    }
    y = (double)(source.first - s) * a;
    return (source.second - seg.start.second) - y < 0 ? false : true;
  }
}

int solve(int sourcex, int sourcey) {
  int segmentc = segments.size();
  struct segment seg;
  int targetx, targety;
  targetx = sourcex;
  targety = sourcey;

  int i;
  for(i = 0;i < segmentc;i++) {
    seg = segments[i];
    if(is_in_range(make_pair(targetx, targety), seg)) {
      targetx = seg.end.first;
      targety = seg.end.second - 1;
    }
  }

  if(targety == sourcey) {
    return targetx;
  }
  if(seg.result != -1) {
    return seg.result;
  }
  return seg.result = solve(targetx, targety);
}

int main() {
  int n, np, ns;
  int x1, x2, y1, y2;

  cin >> n;
  while(n--) {
    cin.ignore();

    segments.clear();
    sources.clear();

    cin >> np;
    for(int j = 0;j < np;j++) {
      cin >> x1 >> y1;
      cin >> x2 >> y2;

      struct segment seg;
      if(y1 > y2) {
        seg.start = make_pair(x1, y1);
        seg.end = make_pair(x2, y2);
      } else {
        seg.start = make_pair(x2, y2);
        seg.end = make_pair(x1, y1);
      }
      segments.push_back(seg);
    }
    sort(segments.begin(), segments.end(), sort_segments);

    cin >> ns;
    for(int j = 0;j < ns;j++) {
      cin >> x1 >> y1;
      sources.push_back(make_pair(x1, y1));
    }

    int size = sources.size();
    for(int j = 0;j < size;j++) {
      cout << solve(sources[j].first, sources[j].second) << endl;
    }

    if(n != 0) {
      cout << endl;
    }
  }

  return 0;
}
