#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Prime {
  public:
    int number;
    int order;
    Prime(){}
    Prime(int n, int o): number(n), order(o) {}
    bool operator<(const Prime& rhs) const {
      return number < rhs.number;
    }

    bool operator<(const int a) {
      return number < a;
    }
};

int main() {
  vector<Prime> primes;
  vector<bool> sieve;
  sieve.resize(1000000, false);
  sieve[0] = sieve[1] = true;
  int curidx = 2;
  int order = 1;
  for(; curidx <= 1000000;) {
    primes.push_back(Prime(curidx, order++));
    for(int i=curidx; i<=1000000; i+=curidx) {
      sieve[i] = true;
    }
    for(;sieve[curidx];curidx++);
  }
  int CASE = 1;
  while(true) {
    int N;
    cin >> N;
    if(N==0) break;
    cout << "Case " << CASE++ << ": ";
    int cnt = 0;
    for(int i=0; i<primes.size(); i++) {
      Prime& cur = primes[i];
      if(cur.number >= N) break;
      int numb = N - cur.number;
      vector<Prime>::iterator it = upper_bound(primes.begin()+i+1, primes.end(), Prime(numb, -1));
      it--;
      if(it == primes.begin()) continue;
      cnt += (*it).order - (i+1);
    }
    cout << cnt << endl;
  }
}
