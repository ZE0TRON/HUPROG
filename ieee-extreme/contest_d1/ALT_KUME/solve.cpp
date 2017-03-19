#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> kume;
  kume.resize(N);
  for(int i=0; i<N; i++) {
    cin >> kume[i];
  }

  /* ASIL KISIM */  
  int size = (1 << N);
  for(int i=1; i<size; i++) {
    for(int mask = 1, idx=0; mask<size; mask = mask << 1, idx++) {
      if(mask & i) {
        cout << kume[idx] << " ";
      }
    }
    cout <<endl;
  }
  /* ASIL KISIM END */
  return 0;
}
