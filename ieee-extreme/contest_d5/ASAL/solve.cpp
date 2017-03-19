#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int rangesum[1000005];
bool sieve[1000005];
vector<int> primes;

bool is_prime(int numb) {
	return binary_search(primes.begin(), primes.end(), numb);
}

int digit_sum(int numb) {
	int res = 0;
	while(numb) {
		res+=(numb%10);
		numb/=10;
	}
	return res;
}

int main() {
	rangesum[0] = 0;
	rangesum[1] = 0;
	sieve[0] = true;
	sieve[1] = true;
	int curidx = 2;
	for(; curidx<1000005; curidx++) {
		for(; curidx < 1000005 && sieve[curidx]; curidx++) {
			rangesum[curidx] = rangesum[curidx-1];
		}
		primes.push_back(curidx);
		for(int i=curidx; i<1000005; i+=curidx) {
			sieve[i] = true;
		}
		if(is_prime(digit_sum(curidx))) {
			rangesum[curidx] = rangesum[curidx-1] + 1;
		} else
			rangesum[curidx] = rangesum[curidx-1];
	}
	int N;
	cin >> N;
	for(int n=0; n<N; n++) {
		int t1, t2;
		cin >> t1 >> t2;
		cout << rangesum[t2] - rangesum[t1-1] << endl;
	}
	return 0;
}
