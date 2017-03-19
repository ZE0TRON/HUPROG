#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  for(int i=0; i<N; i++) {
    long long int left_up = 0;
    long long int left_down = 1;
    long long int right_up = 1;
    long long int right_down = 0;
    long long int cur_up = 1;
    long long int cur_down = 1;
    string comm;
    cin >> comm;
    for(int i=0; i<comm.size(); i++) {
      if(comm[i] == 'R') {
        left_up = cur_up;
        left_down = cur_down;
      } else {
        right_up = cur_up;
        right_down = cur_down;
      }      
      cur_up = left_up + right_up;
      cur_down = left_down + right_down;
    }
    cout << cur_up << "/" << cur_down << endl;
  }
  return 0;
}
