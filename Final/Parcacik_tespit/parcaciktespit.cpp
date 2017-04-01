#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define Max_N 1000001
#define INF 1000000000
int N,color[Max_N],root,from,to,counter,parent[Max_N],s,q,search_here[Max_N],highest,last_occurence[Max_N],where,val,ind ,seg[1<<21],power[25],level,answer[Max_N];
vector<int> myvector[Max_N];
struct transfer
{
    int start,end;
}Node[Max_N];
typedef struct queries qu;
struct queries
{
    int ind ,left,right;
    bool operator<(const qu q)const{
        return right<q.right;
    }
}Q[Max_N];
void DFS(int rooti)
{
    Node[rooti].start=counter;
    counter++;
    while(!myvector[rooti].empty()){
        to=myvector[rooti].back();
        if(to!=parent[rooti]){
            parent[to]=rooti;
            DFS(to);
        }
        myvector[rooti].pop_back();
    }
    Node[rooti].end=counter-1;
}
int search(int low,int high,int s)
{
    int mid=(low+high)>>1;
    if(search_here[mid]==s) return mid;
    else if(search_here[mid]>s) return search(low,mid-1,s);
    else    return search(mid+1,high,s);
}
void constant()
{
    power[0]=1;
    for(int i=1;i<=23;i++)  power[i]=power[i-1]<<1;
}
void obtain(int x)
{
    int y=x;
    level=0;
    while(x){
        x>>=1;
        level++;
    }
    if(power[level-1]!=y)   level++;
}
void update(int pos,int val)
{
    seg[pos]=val;
    pos=pos>>1;
    while(pos){
        seg[pos]=seg[pos<<1]+seg[(pos<<1)+1];
        pos>>=1;
    }
    return;
}
int Query(int s,int e,int i,int j,int node)
{
    if(i>e || s>j)  return 0;
    if(s>=i && j>=e)    return seg[node];
    return (Query(s,((s+e)>>1),i,j,(node<<1))+Query(((s+e)>>1)+1,e,i,j,(node<<1)+1));
}
int main()
{
    int v;
    scanf("%d%d%d",&N,&q,&root);
    //connections
    for(int i=1;i<N;i++){
        scanf("%d%d",&from,&to);
        myvector[from].push_back(to);
        myvector[to].push_back(from);
    }
    counter=1;
    parent[root]=root;
    DFS(root);
    //color of the graph
    for(int i=1;i<=N;i++){
        scanf("%d",&v);
        color[Node[i].start]=v;
        search_here[i]=v;   //finally i need to sort so no troubles
    }


    for(int i=0;i<q;i++){
        scanf("%d",&s);
        Q[i].ind =i;
        Q[i].left=Node[s].start;
        Q[i].right=Node[s].end;
    }
    sort(Q,Q+q);
    sort(search_here+1,search_here+N+1);
    highest=2;
    for(int i=2;i<=N;i++){  
        if(search_here[i]==search_here[highest-1])  continue;
        else{
            search_here[highest]=search_here[i];
            highest++;
        }
    }
    highest--;
    where=0;
    constant();
    obtain(N);
    for(int i=0;i<=N;i++)   last_occurence[i]=-INF;
    memset(seg,0,sizeof(seg));
    //search in search_here from 1 to highest ind ed
    for(int i=1;i<=N;i++){
        val=color[i];
        ind =search(1,highest,val);
        if(last_occurence[ind ]<0){
            last_occurence[ind]=i;
            update(power[level-1]+last_occurence[ind]-1,1);
        }
        else{
            update(power[level-1]-1+last_occurence[ind ],0);
            last_occurence[ind]=i;
            update(power[level-1]-1+last_occurence[ind ],1);
        }
        while(Q[where].right==i){
            answer[Q[where].ind]=Query(1,power[level-1],Q[where].left,Q[where].right,1);
            where++;
        }
    }
    for(int i=0;i<q;i++)    printf("%d\n",answer[i]);
    return 0;
}
