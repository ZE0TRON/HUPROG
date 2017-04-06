#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#define min(x, y) ((x) < (y) ? (x) : (y))
int map[16][16], odd[16];
using namespace std;
void floyd(int n) {
    int i, j, k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
}
int dp[1<<16];
int build(int pN, int ot) {
    if(pN == 0)
        return 0;
    if(dp[pN] != -1)
        return dp[pN];
    int i, j, tmp;
    dp[pN] = 0xfffffff;
    for(i = 0; i < ot; i++) {
        if(pN&(1<<i)) {
            for(j = i+1; j < ot; j++) {
                if(pN&(1<<j)) {
                    tmp = build(pN-(1<<i)-(1<<j), ot);
                    dp[pN] = min(dp[pN], tmp+map[odd[i]][odd[j]]);
                }
            }
            break;
        }
    }
    return dp[pN];
}
int main() {
    int q,n, m, x, y, w;

    ofstream myFileOut;
    string outName;
    cout<<"Dosya sirasi output"<<endl;
    cin>>outName;
    myFileOut.open("output"+outName+".txt");
    string sonuc;
    
    ifstream myFileInp;
    myFileInp.open("input"+outName+".txt");

    myFileInp>>q;

    while(q--) {
        
        myFileInp>>n;
        myFileInp>>m;
        memset(map, 63, sizeof(map));
        memset(dp, -1, sizeof(dp));
        int sum = 0, deg[16] = {};
        while(m--) {
            myFileInp>>x;
            myFileInp>>y;
            myFileInp>>w;
            map[x][y] = min(map[x][y], w);
            map[y][x] = min(map[y][x], w);
            deg[x]++, deg[y]++;
            sum += w;
        }
        floyd(n);
        int ot = 0;
        for(int i = 1; i <= n; i++)
            if(deg[i]&1)
                odd[ot++] = i;
        int temp = sum+build((1<<ot)-1, ot);
        myFileOut<<temp<<endl;
    }
    return 0;
}
