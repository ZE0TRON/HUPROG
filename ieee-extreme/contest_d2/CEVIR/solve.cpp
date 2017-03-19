#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
  string inp;
  while(true) {
    int m,n;
    cin >> m >> n;  
    if(m==0 && n==0) break;
    int x;
    map<int, map<int, int> > transpose;
    for(int i=0; i<n; i++)
      transpose[i] = map<int,int>();
    for(int i=0; i<m; i++) {
      int nonzero;
      cin >> nonzero;
      vector<int> indices(nonzero);
      for(int j=0; j<nonzero; j++) {
        cin >> indices[j];
        indices[j]--;
      }

      vector<int> values(nonzero);
      for(int j=0; j<nonzero; j++) {
        cin >> x;
        transpose[indices[j]][i] = x;
      }
    }


    cout << n << " " << m<<endl;
    for(int i=0; i<n; i++) {
      cout << transpose[i].size() << " ";
      for(map<int, int>::iterator it = transpose[i].begin(); it != transpose[i].end(); it++) {
          cout << it->first+1 << " ";
      }
      cout << endl;
      for(map<int, int>::iterator it = transpose[i].begin(); it != transpose[i].end(); it++) {
        cout << it->second << " ";
      }
      cout <<endl;
      
    }
  }
  return 0;
}
