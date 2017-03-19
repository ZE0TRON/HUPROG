#include <iostream>
#include <vector>
using namespace std;
int main() {
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    int n;
    cin >> n;
    vector<int> coins;
    coins.resize(n);

    for(int i=0; i<n; i++) cin >> coins[i];


    int sum = 0;
    int total = 1;
    for(int i=0; i<n-1; i++) {
      if(sum + coins[i] < coins[i+1]) {
        sum += coins[i];
        total++;
      }
    }

    cout << total << endl;

  }
  return 0;
}
