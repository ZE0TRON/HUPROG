#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
string hasha(vector<int>& cur) {
  string res;
  for(int i=0; i<cur.size(); i++)
    res = res + to_string(cur[i]) + string("-");
  return res;
}
int main() {
  while(true) {
    int N;
    cin >> N;
    if(N==0) break;
    vector<int> cur;
    map<string, int> cnt; 
    cur.resize(5);
    for(int i=0; i<N; i++) {
      cin >> cur[0] >> cur[1] >> cur[2] >> cur[3] >> cur[4];
      sort(cur.begin(), cur.end());
      string hsh = hasha(cur);
      cnt[hsh]++;
    }

    int max_cnt = -1;
    for(map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      max_cnt = max(max_cnt, it->second);
    }

    int count = 0;
    for(map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      if(it->second == max_cnt)
        count += max_cnt;
    }
    cout << count << endl;
  }
  return 0;
}
