#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int L, R, C;
class LOC {
  public:
    int x;
    int y;
    int z;
    int w;
    LOC(){}
    LOC(int a, int b, int c, int v): x(a), y(b), z(c), w(v){}
};

int bfs(vector<vector<vector<char> > >& maze) {
  queue<LOC> Q;
  vector<vector<vector<bool> > > visited;
  visited.resize(L);
  for(int i=0; i<L; i++) {
    visited[i].resize(R);
    for(int j=0; j<R; j++) {
      visited[i][j].resize(C);
      for(int k=0; k<C; k++) {
        visited[i][j][k] = false;
      }
    }
  }
  bool broken = false;
  for(int i=0; i<L; i++) {
    for(int j=0; j<R; j++) {
      for(int k=0; k<C; k++) {
        if(maze[i][j][k] == 'S') {
          Q.push(LOC(i,j,k,0));
          broken = true;
          visited[i][j][k] = true;
          break;
        }
      }
      if(broken) break;
    }
    if(broken) break;
  }
  while(!Q.empty()) {
    LOC front = Q.front();
    Q.pop();
    int x, y, z, w;
    x = front.x; y = front.y; z = front.z; w=front.w;
    if(maze[x][y][z] == 'E') return w;
    x++;
    if(x<L && !visited[x][y][z] && (maze[x][y][z] == '.' || maze[x][y][z] == 'E')) {
      visited[x][y][z] = true;
      Q.push(LOC(x,y,z,w+1));
    }
    x--;x--;
    if(x>-1 && !visited[x][y][z] && (maze[x][y][z] == '.' || maze[x][y][z] == 'E')) {
      visited[x][y][z] = true;
      Q.push(LOC(x,y,z,w+1));
    }
    x++;y++;
    if(y<R && !visited[x][y][z] && (maze[x][y][z] == '.' || maze[x][y][z] == 'E')) {
      visited[x][y][z] = true;
      Q.push(LOC(x,y,z,w+1));
    }
    y--;y--;
    if(y>-1 && !visited[x][y][z] && (maze[x][y][z] == '.' || maze[x][y][z] == 'E')) {
      visited[x][y][z] = true;
      Q.push(LOC(x,y,z,w+1));
    }
    y++;z++;
    if(z<C && !visited[x][y][z] && (maze[x][y][z] == '.' || maze[x][y][z] == 'E')) {
      visited[x][y][z] = true;
      Q.push(LOC(x,y,z,w+1));
    }
    z--;z--;
    if(z>-1 && !visited[x][y][z] && (maze[x][y][z] == '.' || maze[x][y][z] == 'E')) {
      visited[x][y][z] = true;
      Q.push(LOC(x,y,z,w+1));
    }
  }

  return -1;

}

int main() {
  while(true) {
    cin >> L >> R >> C;
    if(L == 0 && R == 0 && C == 0) break;
    vector<vector<vector<char> > > maze;
    maze.resize(L);
    for(int i=0; i<L; i++) {
      maze[i].resize(R);
      for(int j=0; j<R; j++) {
        maze[i][j].resize(C);
      }
    }

    for(int i=0; i<L; i++)
      for(int j=0; j<R; j++)
        for(int k=0; k<C; k++)
          cin >> maze[i][j][k];

    cout << bfs(maze) << endl;
  }
  return 0;
}
