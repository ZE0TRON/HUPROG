#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
bool edge[256][256];
bool visited[256];

void dfs(char idx, stack<char>& topostack) {
  visited[idx] = true;
  for(char i='A'; i<='Z'; i++)
    if(edge[idx][i] && !visited[i])
      dfs(i, topostack);

  topostack.push(idx);
}

stack<char> toposort(map<char, bool> & chrs) {
  for(int i=0; i<256; i++) {
    if((i <= 'Z' && i >= 'A') && chrs.find((char)i) != chrs.end() )
      visited[i] = false;
    else
      visited[i] = true;
  }

  stack<char> topostack;

  for(char i='A'; i<='Z'; i++) {
    if(!visited[i]) {
      dfs(i, topostack);
    }
  }
  return topostack;
}

int main() {
  for(int i=0; i<256; i++)
    for(int j=0; j<256; j++)
      edge[i][j] = false;
  vector<string> strs;
  int max_len = -1;
  string cur;
  map<char, bool> chrs;
  while(true) {
    cin >> cur;
    if(cur == string("#"))
      break;
    strs.push_back(cur);
    max_len = max(max_len, (int)cur.size());
    for(int i=0; i<cur.size(); i++)
      chrs[cur[i]] = true;
  }

  for(int i=0; i<strs.size()-1; i++) {
    int j;
    for(j=0; j < strs[i].size() && j < strs[i+1].size() && strs[i][j] == strs[i+1][j]; j++);
    if(j >= strs[i].size() || j >= strs[i+1].size()) continue;
    edge[strs[i][j]][strs[i+1][j]] = true;
  }

  stack<char> stk = toposort(chrs);

  while(!stk.empty()) {
    char cur = stk.top();
    stk.pop();
    cout << cur;
  }
  cout << endl;
  return 0;
}
