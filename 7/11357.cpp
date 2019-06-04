#include <iostream>
#include <regex>
#include <sstream>
#include <map>

using namespace std;

bool eval(char *c) {
  stringstream ss(c);
  string formula;
  ss >> formula;
  map<string, bool> variables;

  regex variable_regex("(~?[a-z])");
  auto words_begin = sregex_iterator(formula.begin(), formula.end(), variable_regex);
  auto words_end = sregex_iterator();

  for(sregex_iterator i = words_begin;i != words_end;i++) {
    smatch match = *i;
    variables[match.str()] = true;
  }

  string matched_string, key;
  for(sregex_iterator i = words_begin;i != words_end;i++) {
    smatch match = *i;
    matched_string = match.str();

    if(matched_string[0] == '~') {
      key = matched_string[1];
      if(variables.find(key) != variables.end()) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int t;
  string line;
  char *start, *end;
  bool result = true;

  cin >> t;
  for(int i = 0;i < t;i++) {
    cin >> line;
    end = &line[0];
    result = true;

    while(1) {
      result = true;
      start = end;

      while(*end != '|' && *end != '\0') {
        end++;
      }
      if(*end == '\0') {
        result &= eval(start);
        break;
      } else {
        *end = '\0';
        result &= eval(start);
        end++;
      }

      if(result) break;
    }

    if(result) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }

  return 0;
}
