#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <map>
using namespace std;
int main() {
  long long int N, K;
  cin >> N >> K;
  vector<long long int> divisors;
  long long int idx = 0;
  for(long long int i=1; i*i<=N; i++) {
    if(N%i==0) {
      divisors.push_back(i);
      if(i*i != N)
        divisors.push_back(N/i);
    }
  }

  sort(divisors.begin(), divisors.end());

  if(K > divisors.size()) cout << -1 << endl;
  else cout << divisors[K-1] << endl;

  return 0;
}
