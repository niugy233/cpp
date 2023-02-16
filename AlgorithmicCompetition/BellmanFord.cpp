#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define INF 1e5
int pre[MAXN];
struct edge{ int u,v,w;};
edge e[MAXN]; //记录边 （这里暂时有个不明朗的地方五香图与有向图）
int cnt;
int pre[MAXN]; //记录前驱结点 pre[i] = u; i的前驱节点是u


void Bellman(int n){
    int s = 1;
    int d[MAXN]; //记录结点i到结点s的最短距离
    for(int i = 1;i<=n;i++){ d[i] = INF;}
    d[s] = 0;
    for(int k = 0;k<n;k++){
        for(int i = 0;i<cnt;i++){
            if(d[e[i].u] > d[e[i].v] + e[i].w){
                d[e[i].u] = d[e[i].v] + e[i].w;
                pre[e[i].u] = e[i].v; //更换前驱+
            }
        }
    }
}
int main(){
    int n,m,u,v,w;
    while(scanf("%d %d",&n,&m) && n != 0 || m != 0){
        cnt == 0;
        while(m--){ //例题的边是双向的
            cin >> u >> v >> w;
            // 这样记录下来的是无向图但是还具有无向图的特证
            e[cnt].u = u; e[cnt].v = v,e[cnt].w = w; cnt++;
            e[cnt].u = v; e[cnt].v = u,e[cnt].w = w; cnt++;           
        }
    }  
}