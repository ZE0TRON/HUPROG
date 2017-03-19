#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cout << "Case " << t << ": ";
    int N;
    cin >> N;
    string FIELD;
    cin >> FIELD;
    int cnt = 0;
    for(int i=0; i<FIELD.size(); i++) {
      if(FIELD[i] == '#') continue;
      if(i == FIELD.size()-1) cnt++;
      else {
        cnt++;
        FIELD[i+1] = '#';
        if(i+2 < FIELD.size()) FIELD[i+2] = '#';
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
