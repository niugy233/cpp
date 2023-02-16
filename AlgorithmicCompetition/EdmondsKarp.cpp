#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define INF 1e5
int n,m,G[MAXN][MAXN]; //邻接矩阵存图
int pre[MAXN];

// 返回一个路径中最小的一个数据流
int BFS(int s,int t){
    int flow[MAXN]; // 记录结点i在一个回路中时最小的流量（通常有最小流量的管道决定）
    memset(pre,-1,sizeof(pre));
    queue<int> Q;
    pre[s] = INF;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        // 回路完成s到t结束循环返回该路径的最小流
        if( u == t) break; // t没有出度
        for(int i = 1;i<=m;i++){
            // 这就很怪源点应该是米有入度的
            if(pre[i] == -1 && G[u][i] > 0 && s != i){ //该点未访问 && congu到i还有剩余流量 &&  
                pre[i] = u;
                Q.push(i);
                flow[i] = min(flow[u],G[u][i]); // 记录最小口径的管道在该回路中的流量
            }
        }
    }
    if(pre[t] == -1) return -1; //没有找到新的增光路
    return flow[t];
}

int MaxFlow(int s,int t){
    int MaxFlowNum = 0;
    while(1){
        int ans = BFS(s,t);
        if(ans == -1) break; // 找不到任何合理回路
        int cur = t;
        while(cur != s){
            int father = pre[cur];
            G[father][cur] -= ans;
            G[cur][father] += ans;
            cur = father;
        }
        MaxFlowNum += ans;
    }
    return MaxFlowNum;
}
int main(){
    cin >> n >> m;
    while(n != 0 || m != 0){
        int u,v,w;
        memset(G,0,sizeof(G));// 这里初始化为什么是0
        for(int i = 0;i<m;i++){
            cin >> u >> v >> w;
            G[u][v] += w; //防止重边
        }
    }
}