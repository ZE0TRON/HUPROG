#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Edge {
  public:
    int to;
    int weight;
    Edge() {}
    Edge(int t, int w): to(t), weight(w) {}
};

class Val {
  public:
    int node;
    int val;
    Val() {}
    Val(int n, int v): node(n), val(v) {}
    bool operator<(const Val& lhs) const {
      return val < lhs.val;
    }
    bool operator>(const Val& lhs) const {
      return val > lhs.val;
    }
};
int main() {
  /* ! EDGE FLIP */ 
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    int N;
    cin >> N;
    int E;
    cin >> E;
    E--;
    int TIME;
    cin >> TIME;
    int M;
    cin >> M;
    vector<vector<Edge> > edges;
    edges.resize(N);
    for(int i=0; i<M; i++) {
      int a,b,c;
      cin >> a >> b >> c;
      a--; b--;
      edges[b].push_back(Edge(a,c));
    }
    vector<int> dist;
    dist.resize(N, -1);
    priority_queue<Val, vector<Val>, greater<Val> > pq;
    dist[E] = 0;
    pq.push(Val(E, 0));
    while(!pq.empty()) {
      Val front = pq.top(); pq.pop();
      int node = front.node;
      int val = front.val;
      if(dist[node] != -1 && val > dist[node]) continue;
      for(int i=0; i<edges[node].size(); i++) {
        Edge& edge = edges[node][i];
        int to = edge.to;
        int weight = edge.weight;
        if(dist[to] == -1 || (weight + dist[node] < dist[to])) {
          dist[to] = dist[node] + weight;
          pq.push(Val(to, dist[to]));
        }
      }
    }
    int total = 0;
    for(int i=0; i<dist.size(); i++) {
      if(dist[i] < 0) continue;
      if(dist[i] <= TIME)  total++;
    }
    cout << total << endl;
  }
  return 0;
}
