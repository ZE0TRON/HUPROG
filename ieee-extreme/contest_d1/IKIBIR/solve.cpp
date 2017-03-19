#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int gen_int(int mask, int digit_count) {
  long long int res = 0;
  for(int i=digit_count-1; i>=0; i--) {
    res *= 10;
    int cur_mask = 1 << i;
    if(cur_mask & mask)
      res += 2;
    else
      res += 1;
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cout << "Case " << t << ": ";
    int p,q;
    cin >> p >> q;
    q = 1 << q;
    int mx = 1<<p;
    long long int first = -1;
    long long int second = -1;
    for(int mask = 0; mask < mx; mask++) {
      long long int cur = gen_int(mask, p);
      if(cur % q == 0) {
        if(first == -1) first = cur;
        else second = cur;
      }
    }
    if(first == -1)
      cout << "impossible" << endl;
    else if(second == -1)
      cout << first << endl;
    else
      cout << first << " " << second << endl;
  }
  return 0;
}
