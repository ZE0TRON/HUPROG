#include <iostream>
using namespace std;
int ARR[10050];
int DP[105][10050];
int N, K;

bool doable(int sum, int pos) {
	sum += K*1000;
	sum %= K;

	if(pos == N)
		return sum == 0;
	if(DP[sum][pos] != -1) return DP[sum][pos] == 1;

	bool res = false;

	res |= doable(sum + ARR[pos], pos+1);
	res |= doable(sum - ARR[pos], pos+1);

	if(res)
		DP[sum][pos] = 1;
	else
		DP[sum][pos] = 0;

	return res;
}

int main() {
	int M;
	cin >> M;
	for(int m=1; m<=M; m++) {
		cin >> N >> K;
		for(int i=0; i<K; i++)
			for(int j=0; j<N; j++)
				DP[i][j] = -1;

		for(int i=0; i<N; i++)
			cin >> ARR[i];

		if(doable(0, 0))
			cout << "Bolunebilir"  << endl;
		else
			cout << "Bolunemez" << endl;
	}
	return 0;
}
