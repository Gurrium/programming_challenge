#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <cstring>
#define INF 1000

using namespace std;

map<char, bool> young_visited, major_visited;

int main() {
  int n;
  char type, u_or_b, from, to;
  char my_place, prof_place;
  int energy;
  vector<pair<int, int> > yg[26], mg[26];
  array<int, 26> ydist, mdist;

  cin >> n;
  while(n != 0) {
    for(int i = 0;i < 26;i++) {
      yg[i].clear();
      mg[i].clear();
    }
    ydist.fill(INF);
    mdist.fill(INF);

    for(int i = 0;i < n;i++) {
      cin >> type >> u_or_b >> from >> to >> energy;
      from -= 'A';
      to -= 'A';

      if(type == 'Y') {
        pair<int, int> dst(to, energy);
        yg[from].push_back(dst);
        if(u_or_b == 'B') {
          pair<int, int> dst(from, energy);
          yg[to].push_back(dst);
        }
      } else if(type == 'M') {
        pair<int, int> dst(to, energy);
        mg[from].push_back(dst);
        if(u_or_b == 'B') {
          pair<int, int> dst(from, energy);
          mg[to].push_back(dst);
        }
      }
    }

    cin >> my_place >> prof_place;
    bool yvisited[26], mvisited[26];
    memset(yvisited, false, sizeof(yvisited));
    memset(mvisited, false, sizeof(mvisited));

    ydist[my_place - 'A'] = 0;
    yvisited[my_place - 'A'] = true;
    for(int j = 0;j < 25;j++) {
      for(int k = 0;k < 26;k++) {
        for(int l = 0;l < yg[k].size();l++) {
          to = yg[k][l].first;
          ydist[to] = min(ydist[to], ydist[k] + yg[k][l].second);
          yvisited[to] = true;
        }
      }
    }

    mdist[prof_place - 'A'] = 0;
    mvisited[prof_place - 'A'] = true;
    for(int j = 0;j < 25;j++) {
      for(int k = 0;k < 26;k++) {
        for(int l = 0;l < mg[k].size();l++) {
          to = mg[k][l].first;
          mdist[to] = min(mdist[to], mdist[k] + mg[k][l].second);
          mvisited[to] = true;
        }
      }
    }

    int min_energy = INF;
    vector<int> min_places;
    for(int j = 0;j < 26;j++) {
      if(yvisited[j] & mvisited[j]) {
        if(min_energy > mdist[j] + ydist[j]) {
          min_energy = mdist[j] + ydist[j];
          min_places.clear();
          min_places.push_back(j + 'A');
        } else if(min_energy == mdist[j] + ydist[j]) {
          min_places.push_back(j + 'A');
        }
      }
    }

    if(min_energy == INF) {
      cout << "You will never meet.";
    } else {
      cout << min_energy << ' ';
      int j = 0;
      int size = min_places.size();
      for(j = 0;j < size - 1;j++) {
        printf("%c ", min_places[j]);
      }
      printf("%c", min_places[j]);
    }
    cout << endl;

    cin >> n;
  }
}
