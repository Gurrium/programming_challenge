#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kill(int head, int min_knight, vector<int> knights) {
  int size = knights.size();

  for(int i = min_knight;i < knights.size();i++) {
    if(head <= knights[i])
      return i;
  }

  return -1;
}

int main() {
  int n, m;
  int head, knight;
  int max_head, max_knight, min_knight_can_beat;
  int result, coin;
  vector<int> heads, knights;

  while(1) {
    cin >> n >> m;
    if(n + m == 0) break;

    coin = max_head = max_knight = 0;
    heads.clear();
    knights.clear();
    while(n--) {
      cin >> head;
      if(head > max_head) max_head = head;
      heads.push_back(head);
    }
    sort(heads.begin(), heads.end());

    while(m--) {
      cin >> knight;
      if(knight > max_knight) max_knight = knight;
      knights.push_back(knight);
    }
    sort(knights.begin(), knights.end());

    min_knight_can_beat = distance(knights.begin(), upper_bound(knights.begin(), knights.end(), heads[0] - 1));
    if(knights.size() - min_knight_can_beat < heads.size() || max_head > max_knight) {
      cout << "Loowater is doomed!" << endl;
      continue;
    }

    for(int i = 0;i < heads.size();i++) {
      result = kill(heads[i], min_knight_can_beat, knights);
      if(result != -1) {
        coin += knights[result];
        min_knight_can_beat = result + 1;
      } else {
        cout << "Loowater is doomed!" << endl;
        break;
      }
    }

    if(result != -1)
      cout << coin << endl;
  }

  return 0;
}
