#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;
int M, Y, PE, OF, OE, MA;
int pathlen[103][103];
int pathlen2[103][103];
bool yassah[103];
int main() {
  while(true) {
    cin >> M >> Y >> PE >> OF >> OE >> MA;
    if(M==0 && Y==0 && PE==0 && OF==0 && OE==0 && MA==0) break;
    for(int i=1; i <= M; i++)
      for(int j=1; j <= M; j++)
        pathlen2[i][j] = pathlen[i][j] = -1;
    for(int i=1; i<= M; i++) {
      pathlen[i][i] = pathlen2[i][i] = yassah[i] = 0;
    }
    for(int i=0; i<Y; i++) {
      int p1, p2, d;
      cin >> p1 >> p2 >> d;
      pathlen2[p1][p2] = pathlen2[p2][p1] = pathlen[p1][p2] = pathlen[p2][p1] = d;
    }

    for(int k=1; k<=M; k++)
      for(int i=1; i<=M; i++)
        for(int j=1; j<=M; j++) {
          if(pathlen[i][k] == -1 || pathlen[k][j] == -1) continue;
          if(pathlen[i][j]==-1) pathlen[i][j] = pathlen[i][k] + pathlen[k][j];
          else pathlen[i][j] = min(pathlen[i][j], pathlen[i][k] + pathlen[k][j]);
        }

    for(int i=1; i<=M; i++) {
      if(pathlen[PE][OF] == pathlen[PE][i] + pathlen[i][OF]) yassah[i] = true;
    }

    if(yassah[OE] || yassah[MA]) {
      cout << "GG" << endl;
      continue;
    }

    for(int k=1; k<=M; k++) {
      if(yassah[k]) continue;
      for(int i=1; i<=M; i++) {
        if(yassah[i]) continue;
        for(int j=1; j<=M; j++) {
          if(yassah[j]) continue;
          if(pathlen2[i][k] == -1 || pathlen2[k][j] == -1) continue;
          if(pathlen2[i][j]==-1) pathlen2[i][j] = pathlen2[i][k] + pathlen2[k][j];
          else pathlen2[i][j] = min(pathlen2[i][j], pathlen2[i][k] + pathlen2[k][j]);
        }
      }
    }

    if(pathlen2[OE][MA] == -1)
      cout << "GG" << endl;
    else
      cout << pathlen2[OE][MA] << endl;
  }
  return 0;
}
