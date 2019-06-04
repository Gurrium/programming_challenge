#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void rot(char *c) {
  for(;*c != '\0';c++) {
    if(*c == ' ') {
      *c = 'A';
    } else if(*c == 'Z') {
      *c = ' ';
    } else {
      *c = *c + 1;
    }
  }
}

int main() {
  string line;
  map<string, int> dictionary;

  cin >> line;
  while(line[0] != '#') {
    dictionary[line] = 1;

    cin >> line;
  }

  int result, max_result;
  int correct_i;
  result = max_result = 0;

  getline(cin, line); // read '\n' after '#'
  getline(cin, line);
  string tmp = line;
  string word;
  for(int i = 0;i < 28;i++) {
    result = 0;
    stringstream ss(tmp);

    while(ss >> word) {
      result += dictionary.find(word) != dictionary.end() ? 1 : 0;
    }

    if(max_result < result) {
      max_result = result;
      correct_i = i;
    }

    rot(&tmp[0]);
  }

  for(int i = 0;i < correct_i;i++) {
    rot(&line[0]);
  }

  int prev_space_index, space_index, newline_index;
  prev_space_index = space_index = newline_index = 0;
  int i;
  for(i = 0;line[i] != '\0';i++) {
    if(line[i] == ' ') {
      prev_space_index = space_index;
      space_index = i;

      if(space_index - newline_index > 60) {
        line[prev_space_index] = '\n';
        newline_index = prev_space_index;
      }
    }
  }
  // remove trailing whitespace
  if(line[i - 1] == ' ') {
    line[i - 1] = '\0';
  }

  for(char *c = &line[0];*c != '\0';c++) {
    cout << *c;
  }
  cout << endl;

  return 0;
}
