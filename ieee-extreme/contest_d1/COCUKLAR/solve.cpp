#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
  while(true) {
    long long int n;
    cin >> n;
    if(n==0) break;
    vector<long long int> vals;
    map<int, vector<pair<int,int> > > pairs;
    vals.resize(n);
    for(long long int i=0; i<n; i++)
      cin>>vals[i];

    sort(vals.begin(), vals.end());

    for(int i=0; i<n; i++) {
      for(int j=i+1;j<n;j++) {
        int idx = vals[i]+vals[j];
        pairs[idx].push_back(make_pair(vals[i],vals[j]));
      }
    }

    bool printed = false;

    for(int i=vals.size()-1; i>=0; i--) {
      int d = vals[i];
      for(int j=0; j<vals.size(); j++) {
        if(i==j) continue;
        int c = vals[j];
        int sum = d-c;
        if(pairs.find(sum) == pairs.end()) continue;
        for(int p=0; p<pairs[sum].size(); p++) {
          int a = pairs[sum][p].first;
          int b = pairs[sum][p].second;
          if(a == c || a == d || b == c || b == d) continue;
          cout << d << endl;
          printed = true;
          break;
        }
        if(printed) break;
      }
      if(printed) break;
    }
    if(!printed)
      cout << "no solution" << endl;
  }
}
