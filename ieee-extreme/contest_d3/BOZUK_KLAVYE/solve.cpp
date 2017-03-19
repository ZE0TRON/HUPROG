#include <iostream>
#include <list>
#include <iterator>
using namespace std;
int main() {
  string line;
  while(getline(cin, line)) {
    list<char> lst;
    list<char>::iterator it = lst.begin();
    for(int i=0; i<line.size(); i++) {
      if(line[i] == '[')
        it = lst.begin();
      else if(line[i] == ']')
        it = lst.end();
      else {
        lst.insert(it, line[i]);
      }
    }

    for(list<char>::iterator it=lst.begin(); it!=lst.end(); it++) {
      cout << (*it);
    }
    cout << endl;
  }
  return 0;
}
