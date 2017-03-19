#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int P[200010];
int FIND(int x) {
  if(P[x] < 0) return x;
  else return P[x] = FIND(P[x]);
}

void UNION(int x, int y) {
  int par_x = FIND(x);
  int par_y = FIND(y);
  if(par_x == par_y) return;
  if(P[par_x] < P[par_y]) {
    P[par_x] += P[par_y];
    P[par_y] = par_x;
  } else {
    P[par_y] += P[par_x];
    P[par_x] = par_y;
  }
}

class Edge {
  public:
    int from;
    int to;
    int weight;
    Edge(){}
    Edge(int f, int t, int w): from(f), to(t), weight(w) {}
    bool operator<(const Edge& rhs) const {
      return weight < rhs.weight;
    }
};

int main() {
  while(true) {
    int m,n;
    int total_weight = 0;
    cin >> m >> n;
    if(m==0 && n==0) break;
    for(int i=0; i<m; i++)
      P[i] = -1;
    vector<Edge> edges;
    edges.resize(n);
    int a,b,c;
    for(int i=0; i<n; i++) {
      cin >> a >> b >> c;
      total_weight += c;
      edges[i] = Edge(a,b,c);
    }
    sort(edges.begin(), edges.end());
    int used_weight = 0;
    for(int i=0; i<edges.size(); i++) {
      int par_x = FIND(edges[i].from);
      int par_y = FIND(edges[i].to);
      if(par_x != par_y) {UNION(edges[i].from, edges[i].to); used_weight+=edges[i].weight;}
    }
    cout << total_weight - used_weight << endl;
  }
  return 0;
}
