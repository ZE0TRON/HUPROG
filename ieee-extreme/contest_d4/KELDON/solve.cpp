#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > adjlist;

bool diff(string a, string b) {
  if(a.size() != b.size()) return false;

  int diff_cnt = 0;
  for(int i=0; i<a.size(); i++)
    if(a[i] != b[i]) diff_cnt++;
  return diff_cnt <= 1;
}

int main() {
  int N;
  cin >> N;
  for(int n=0; n<N; n++) {
    adjlist.clear();
    vector<string> words;
    string cur;
    cin >> cur;
    while(cur != string("*")) {
      words.push_back(cur);
      cin >> cur;
    }
    adjlist.resize(words.size());
    for(int i=0; i<adjlist.size(); i++)
      adjlist[i].resize(words.size(), 0);

    for(int i=0; i<adjlist.size(); i++) {
      for(int j=0; j<adjlist.size(); j++) {
        if(diff(words[i], words[j])) {
          adjlist[i][j] = 1;
        }
      }
    }


    vector<pair<int, int> > start_end;

    getline(cin, cur);getline(cin, cur);
    while(cur != string("")) {
      string first;
      string second;
      int i;
      for(i=0; cur[i] != ' '; i++)
        first.push_back(cur[i]);
      i++;
      for(; i<cur.size(); i++)
        second.push_back(cur[i]);

      int first_idx;
      int second_idx;
      for(int i=0; i<words.size(); i++) {
        if(first == words[i]) first_idx = i;
        if(second == words[i]) second_idx = i;
      }

      start_end.push_back(make_pair(first_idx, second_idx));
      getline(cin, cur);
    }

    for(int i=0; i<start_end.size(); i++) {
      int from = start_end[i].first;
      int to = start_end[i].second;

      vector<bool> visited;
      visited.resize(words.size(), false);

      queue<pair<int, int> > Q;
      Q.push(make_pair(from, 0));
      visited[from] = true;
      while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        int word_idx = cur.first;
        int len = cur.second;
        if(word_idx == to) {
          cout << words[from] << " " << words[to] << " " << len << endl;
          break;
        }

        for(int i=0; i<words.size(); i++) {
          if(adjlist[word_idx][i] == 1 && !visited[i]) {
            visited[i] = true;
            Q.push(make_pair(i, len+1));
          }
        }

      }
    }
    if(n!=N-1)
      cout << endl;
  }
  return 0;
}
