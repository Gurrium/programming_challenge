#include <iostream>
#include <vector>

using namespace std;

struct node {
  node *zero;
  node *one;
  bool is_code = false;
};
struct node root;

bool build_tree(char *c) {
  struct node *current = &root;

  while(*c != '\0') {
    if(*c == '0') {
      if(current->zero == NULL) break;
      current = current->zero;
    } else if(*c == '1') {
      if(current->one == NULL) break;
      current = current->one;
    }

    c++;
  }

  // dup key
  if(*c == '\0') {
    return false;
  }

  for(;*c != '\0';c++) {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->zero = NULL;
    new_node->one = NULL;
    if(*c == '0') {
      current->zero = new_node;
    } else if(*c == '1') {
      current->one = new_node;
    }
    current = new_node;
  }
  return current->is_code = true;
}

bool check_tree(char *c) {
  struct node *current = &root;

  for(;*c != '\0';c++) {
    current = *c == '0' ? current->zero : current->one;
  }

  if(!(current->zero == NULL && current->one == NULL)) {
    return false;
  }

  return true;
}

int main() {
  string line;
  bool result = true;
  int size, counter = 1;
  vector<string> strings;

  cin >> line;
  while(!cin.eof()) {
    result = true;
    strings.clear();
    // sorry GC XD
    root.zero = NULL;
    root.one = NULL;

    while(line[0] != '9') {
      if(!build_tree(&line[0])) {
        result = false;
      }
      strings.push_back(line);

      cin >> line;
    }

    if(result) {
      size = strings.size();
      for(int i = 0;i < size;i++) {
        result &= check_tree(&strings[i][0]);
      }
    }

    cout << "Set " << counter++ << " is";
    if(!result) {
      cout << " not";
    }
    cout << " immediately decodable" << endl;

    cin >> line;
  }

  return 0;
}
