/* 基于链式前向星的存储方式 */

#include <bits/stdc++.h>
using  namespace std;

#define MAXN 100
#define INF 1e5
struct edge{
    int to,next,w;
}edge[MAXN];
int head[MAXN];
int pre[MAXN];
int dis[MAXN];
int ing[MAXN];
int cnt; //记录edge数组位置

void init(int m){
    for(int i = 0;i<= 2*m;i++){
        edge[i].next = -1;
        head[i] = -1;
    }
    cnt = 0;
}
void AddEdge(int u,int v,int w){
    edge[cnt].to = v; // 到达的结点v
    edge[cnt].next = head[u]; //结点u的下一个邻居的结点位置
    edge[cnt].w = w;
    head[u] = cnt++;
}

void SPFA(int n){
    int s = 1;
    ing[s] = true;
    dis[s] = 0;
    queue<int> Q;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        while(edge[head[u]].next != -1){
            int v = edge[head[u]].next;
            int w = edge[head[u]].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pre[v] = u;
            }
            if(!ing[v]){
                ing[v] = true;
                Q.push(v);
            }
        }
    }
}
int main(){
    int n,m,u,v,w;
    while(scanf("%d %d" ,&n, &m) && n!=0 || m != 0){
        init(m);
        while(m--){
            cin >> u >> v >> w;
            AddEdge(u,v,w);
            AddEdge(v,u,w);
        }
        SPFA(1);
    }
    return 0;
}