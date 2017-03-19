#include <iostream>
using namespace std;
int cuts[55];
int dp[55][55];
int n;

int cost(int start, int end) {
	if(dp[start][end] != -1) return dp[start][end];

	int mn = -1;

	for(int i=start+1; i<end; i++) {
		if(mn == -1) mn = cost(start, i) + cost(i, end);
		else mn = min(mn, cost(start, i) + cost(i, end));
	}

	return dp[start][end] = mn + (cuts[end] - cuts[start]);
}

int main() {
	while(true) {
		for(int i=0; i<55; i++)
			for(int j=0; j<55; j++)
				dp[i][j] = -1;

		for(int i=0; i<54; i++)
			dp[i][i+1] = 0;
		int l;
		cin >> l;
		if(l==0) break;
		cin >> n;

		cuts[0] = 0;
		for(int i=1; i<=n; i++) cin >> cuts[i];
		n++;
		cuts[n] = l;
		n++;

		cout << cost(0, n-1) << endl;
	}
	return 0;
}



