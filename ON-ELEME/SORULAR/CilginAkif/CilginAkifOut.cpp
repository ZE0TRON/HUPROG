#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define M(x) ( (x)%MOD )
#define MOD 10009
#define MAXN 100005
#define MAXT 262150
using namespace std;
typedef pair < int , int > pii;
vector < int > G[MAXN];
pii ST[MAXT] , ST2[MAXT];
int N,Q,dis;
int F[MAXN] , S[MAXN] , T[MAXN];
int dad[MAXN] , depth[MAXN] , heavy[MAXN];
int parent[MAXN] , size[MAXN];
void dfs(int x,int pre)
{
    size[x] = 1;
    vector < int > :: iterator it;
    for( it = G[x].begin(); it != G[x].end(); ++it )
        if( *it != pre )
        {
            int a = *it;
            depth[a] = depth[x] + 1;
            parent[a] = x;
            dfs(a,x);
            size[x] += size[a];
            if( size[a] > size[ heavy[x] ] )
                heavy[x] = a;
        }
}
void dfs2(int x,int pre)
{
    S[x] = ++dis;
    T[dis] = M( T[dis-1] + size[x] );
    if( heavy[x] )
    {
        dad[ heavy[x] ] = dad[x];
        dfs2(heavy[x],x);
    }
    vector < int > :: iterator it;
    for( it = G[x].begin(); it != G[x].end(); ++it )
        if( *it != pre && *it != heavy[x] )
        {
            dad[*it] = *it;
            dfs2(*it,x);
        }

    F[x] = dis;
}
void upd(int pos,int s,int e,int t)
{
    ST[pos].f = M( ST[pos].f + ( T[e] - T[s-1] + MOD ) * t );
    ST[pos].s = M( ST[pos].s + t );
}
void update(int pos,int s,int e,int a,int b,int t)
{
    if( a > e || b < s ) return;
    if( a <= s && e <= b ) return void( upd(pos,s,e,t) );

    int m = ( s + e ) >> 1;
    int sol = pos << 1;
    int sag = sol | 1;

    upd( sol,s,m,ST[pos].s );
    upd( sag,m+1,e,ST[pos].s );
    ST[pos].s = 0;

    update( sol,s,m,a,b,t );
    update( sag,m+1,e,a,b,t );

    ST[pos].f = M( ST[sol].f + ST[sag].f );

}
int sum(int pos,int s,int e,int a,int b)
{
    if( a > e || b < s ) return 0;
    if( a <= s && e <= b ) return ST[pos].f;

    int m = ( s + e ) >> 1;
    int sol = pos << 1;
    int sag = sol | 1;

    upd( sol,s,m,ST[pos].s );
    upd( sag,m+1,e,ST[pos].s );
    ST[pos].s = 0;

    return M( sum( sol,s,m,a,b ) + sum( sag,m+1,e,a,b ) );
}
void upd2(int pos,int s,int e,int t)
{
    ST2[pos].f = M( ST2[pos].f + t * (e - s + 1) );
    ST2[pos].s = M( ST2[pos].s + t );
}
void update2(int pos,int s,int e,int a,int b,int t)
{
    if( a > e || b < s ) return;
    if( a <= s && e <= b ) return void( upd2(pos,s,e,t) );

    int m = ( s + e ) >> 1;
    int sol = pos << 1;
    int sag = sol | 1;

    upd2(sol,s,m,ST2[pos].s);
    upd2(sag,m+1,e,ST2[pos].s);
    ST2[pos].s = 0;

    update2(sol,s,m,a,b,t);
    update2(sag,m+1,e,a,b,t);

    ST2[pos].f = M( ST2[sol].f + ST2[sag].f );

}
int sum2(int pos,int s,int e,int a,int b)
{
    if( a > e || b < s ) return 0;
    if( a <= s && e <= b ) return ST2[pos].f;

    int m = ( s + e ) >> 1;
    int sol = pos << 1;
    int sag = sol | 1;

    upd2(sol,s,m,ST2[pos].s);
    upd2(sag,m+1,e,ST2[pos].s);
    ST2[pos].s = 0;

    return M( sum2( sol,s,m,a,b ) + sum2( sag,m+1,e,a,b ) );
}
int LCA(int a,int b)
{
    while( dad[a] != dad[b] )
        if( depth[ dad[a] ] > depth[ dad[b] ] )
            a = parent[ dad[a] ];
        else
            b = parent[ dad[b] ];

    return depth[a] < depth[b] ? a : b;
}
void up(int a,int b,int t)
{
    while( dad[a] != dad[b] )
    {
        update(  1,1,N, S[ dad[a] ] , S[a] , t );
        update2( 1,1,N, S[ dad[a] ] , S[a] , t );
        a = parent[ dad[a] ];
    }
    update(  1,1,N, S[b] , S[a] , t );
    update2( 1,1,N, S[b] , S[a] , t );
}
int main()
{
    ofstream myFileOut;
    string outName;
    cout<<"Dosya sirasi output"<<endl;
    cin>>outName;
    myFileOut.open("output"+outName+".txt");
    string sonuc;
    
    ifstream myFileInp;
    myFileInp.open(outName+".txt");

    int a,b,c,i,j,res,s,t,type;
    string temp1;
    myFileInp>>temp1;
    N = stoi(temp1);
    cout<<N<<endl;

    FOR(i,1,N-1)
    {
        string temp3,temp4;
        myFileInp>>temp3;
        myFileInp>>temp4;
        
        a = stoi(temp3); b = stoi(temp4);
        cout<<a<<endl;
        cout<<b<<endl;
        G[a].pb(b);
        G[b].pb(a);
    }


    dfs(1,-1);
    dad[1] = 1;
    dfs2(1,-1);
    string temp2;
    myFileInp>>temp2;
    Q = stoi(temp2);
    cout<<Q<<endl;

    while(Q--)
    {
        string temp5,temp6,temp7,temp8;
        myFileInp>>temp5;
        myFileInp>>temp6;
       

        type = stoi (temp5); a = stoi (temp6);
        cout<<type<<endl;
        cout<<a<<endl;
        if( type == 1 )
        {
             myFileInp>>temp7;
             myFileInp>>temp8;
            b = stoi (temp7); t = stoi (temp8);
            cout<<b<<endl;
            cout<<t<<endl;
            c = LCA(a,b);
            up(a,c,t);
            up(b,c,t);
            update(  1,1,N,S[c],S[c] , MOD-t );
            update2( 1,1,N,S[c],S[c] , MOD-t );
        }
        else
        {
            b = parent[a];
            s = 0;
            while(b)
            {
                s = M( s + sum2( 1,1,N, S[ dad[b] ] , S[b] ) );
                b = parent[ dad[b] ];
            }
            sonuc+= to_string(M( s * size[a] + sum( 1,1,N,S[a],F[a] ) )) + "\n";
            
            
        }
    }
    myFileOut << sonuc;
    myFileOut.close();

    return 0;
}
