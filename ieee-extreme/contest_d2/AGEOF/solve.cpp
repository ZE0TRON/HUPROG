#include <iostream>
#include <vector>
using namespace std;
vector<int> segtree;
vector<char> lazy;
string desc;
int N;

void build(int idx, int L, int R) {
  if(L==R) segtree[idx] = desc[L] - '0';
  else {
    int mid = (L+R)/2;
    build(idx << 1, L, mid);
    build(1 + (idx << 1), mid+1, R);
    int rval = segtree[idx<<1];
    int lval = segtree[1+(idx<<1)];
    segtree[idx] = rval + lval;
  }
}

void updateRange(int idx, int L, int R, int qL, int qR, char opr) {
  if(lazy[idx] != 'N') {
    if(lazy[idx] == 'F')
      segtree[idx] = R-L+1;
    else if(lazy[idx] == 'E')
      segtree[idx] = 0;
    else
      segtree[idx] = R-L+1 - segtree[idx];
    if(L != R) {
      if(lazy[idx] == 'F') {
        lazy[idx<<1] = lazy[idx];
        lazy[1+(idx<<1)] = lazy[idx];
      }
      else if(lazy[idx] == 'E') {
        lazy[idx<<1] = lazy[idx];
        lazy[1+(idx<<1)] = lazy[idx];
      }
      else {
        if(lazy[idx<<1] == 'F')
          lazy[idx<<1] = 'E';
        else if(lazy[idx<<1] == 'E')
          lazy[idx<<1] = 'F';
        else if(lazy[idx<<1] == 'I')
          lazy[idx<<1] = 'N';
        else
          lazy[idx<<1] = 'I';
      
        if(lazy[1+(idx<<1)] == 'F')
          lazy[1+(idx<<1)] = 'E';
        else if(lazy[1+(idx<<1)] == 'E')
          lazy[1+(idx<<1)] = 'F';
        else if(lazy[1+(idx<<1)] == 'I')
          lazy[1+(idx<<1)] = 'N';
        else
          lazy[1+(idx<<1)] = 'I';
      }
    }
    lazy[idx] = 'N';
  }
  if(L > qR || R < qL)
    return;
  if(L >= qL && R <= qR) {
    if(opr == 'F')
      segtree[idx] = R-L+1;
    else if(opr == 'E')
      segtree[idx] = 0;
    else
      segtree[idx] = R-L+1 - segtree[idx];
    if(L != R) {
      
      if(opr == 'F') {
        lazy[idx<<1] = opr;
        lazy[1+(idx<<1)] = opr;
      }
      else if(opr == 'E') {
        lazy[idx<<1] = opr;
        lazy[1+(idx<<1)] = opr;
      }
      else {
        if(lazy[idx<<1] == 'F')
          lazy[idx<<1] = 'E';
        else if(lazy[idx<<1] == 'E')
          lazy[idx<<1] = 'F';
        else if(lazy[idx<<1] == 'I')
          lazy[idx<<1] = 'N';
        else
          lazy[idx<<1] = 'I';
      
        if(lazy[1+(idx<<1)] == 'F')
          lazy[1+(idx<<1)] = 'E';
        else if(lazy[1+(idx<<1)] == 'E')
          lazy[1+(idx<<1)] = 'F';
        else if(lazy[1+(idx<<1)] == 'I')
          lazy[1+(idx<<1)] = 'N';
        else
          lazy[1+(idx<<1)] = 'I';
      }
    }
    return;
  }
  int mid = (L+R)/2;
  updateRange(idx<<1, L, mid, qL, qR, opr);
  updateRange(1+(idx<<1), mid+1, R, qL, qR, opr);
  segtree[idx] = segtree[idx<<1] + segtree[1+(idx<<1)];
}

int query(int idx, int L, int R, int qL, int qR) {
  if(L > qR || R < qL)
    return 0;
  if(lazy[idx] != 'N') {
    if(lazy[idx] == 'F')
      segtree[idx] = R-L+1;
    else if(lazy[idx] == 'E')
      segtree[idx] = 0;
    else
      segtree[idx] = R-L+1 - segtree[idx];
    if(L != R) {
      if(lazy[idx] == 'F') {
        lazy[idx<<1] = lazy[idx];
        lazy[1+(idx<<1)] = lazy[idx];
      }
      else if(lazy[idx] == 'E') {
        lazy[idx<<1] = lazy[idx];
        lazy[1+(idx<<1)] = lazy[idx];
      }
      else {
        if(lazy[idx<<1] == 'F')
          lazy[idx<<1] = 'E';
        else if(lazy[idx<<1] == 'E')
          lazy[idx<<1] = 'F';
        else if(lazy[idx<<1] == 'I')
          lazy[idx<<1] = 'N';
        else
          lazy[idx<<1] = 'I';
      
        if(lazy[1+(idx<<1)] == 'F')
          lazy[1+(idx<<1)] = 'E';
        else if(lazy[1+(idx<<1)] == 'E')
          lazy[1+(idx<<1)] = 'F';
        else if(lazy[1+(idx<<1)] == 'I')
          lazy[1+(idx<<1)] = 'N';
        else
          lazy[1+(idx<<1)] = 'I';
      }
    }
    lazy[idx] = 'N';
  }

  if(L >= qL && R <= qR) {
    return segtree[idx];
  }
  int mid = (L+R) / 2;
  return query(idx<<1, L, mid, qL, qR) + query(1+(idx<<1), mid+1 ,R, qL, qR);
}

int main() {
  int T;
  cin >> T;
  for(int t=0; t<T; t++) {
    cout << "Case " << t+1 << ":" << endl;
    int P;
    cin >> P;
    desc.clear();
    for(int p=0; p<P; p++) {
      int num;
      string cur;
      cin >> num >> cur;
      for(int i=0; i<num; i++) desc += cur;
    }
    N = desc.size();
    segtree.clear();
    lazy.clear();
    segtree.resize(N * 4);
    lazy.resize(N * 4, 'N');
    build(1, 0, N-1);
    int Q;
    cin >> Q;
    int qcount = 1;
    for(int q=0; q<Q; q++) {
      char type;int f;int s;
      cin >> type >> f >> s;
      if(type == 'S') {
        cout << "Q" << qcount++ << ": " << query(1, 0, N-1, f, s) << endl;
      } else {
        updateRange(1, 0, N-1, f, s, type);
      }
    }
  }
  return 0;
}
