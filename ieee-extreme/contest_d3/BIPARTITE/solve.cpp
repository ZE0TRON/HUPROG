#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > adjlist;
bool bicolorable() {
  queue<int> q;
  vector<bool> visited;
  int total_visited = 0;
  vector<char> color; // N > NO COLOR, 0 > 1st color, 1 > 2nd color
  visited.resize(adjlist.size(), false);
  color.resize(adjlist.size(), 'N');
  while(total_visited != adjlist.size()) {
    for(int i=0; i<adjlist.size(); i++) {
      if(!visited[i]) {
        q.push(i);
        visited[i] = true;
        color[i] = '0';
        total_visited++;
        break;
      }
    }
    while(!q.empty()) {
      int cur = q.front();
      q.pop();
      for(int i=0; i<adjlist[cur].size(); i++) {
        if(visited[adjlist[cur][i]] && color[adjlist[cur][i]] == color[cur]) return false;
        if(visited[adjlist[cur][i]]) continue;
        q.push(adjlist[cur][i]);
        visited[adjlist[cur][i]] = true;
        color[adjlist[cur][i]] = '1' - color[cur] + '0';
        total_visited++;
      }
    }
  }
  return true;
}

int main() {
  while(true) {
    int n;
    cin >> n;
    if(n == 0) break;
    adjlist.clear();
    for(int i=0; i<n; i++)
      adjlist.push_back(vector<int>());
    int l;
    cin >> l;
    for(int i=0; i<l; i++) {
      int a,b;
      cin >> a >> b;
      adjlist[a].push_back(b);
      adjlist[b].push_back(a);
    }
    cout << (bicolorable() ? "BIPARTITE." : "BIPARTITE DEGIL.") << endl;
  }
  return 0;
}
