/* 邻接表+SPFA+最大流 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
#define INF 1e5
int pre[MAXN];
int preve[MAXN];
int dis[MAXN];
struct edge{
    int to,cost,capacity,rev; // rev 用于记录前驱节点
    edge(int to_,int cost_,int capacity_,int rev_){
        to = to_; cost = cost_; capacity = capacity_; rev = rev_;
    }
};
vector<edge> e[MAXN];
int n,m;
void AddEdge(int from,int to,int cost,int capacity){
    e[from].push_back(edge(to,cost,capacity,e[to].size()));
    e[to].push_back(edge(from,-cost,0,e[from].size() - 1));
}
// s是起点，t是终点，cnt 是结点数量
bool SPFA(int s,int t,int cnt){
    bool ing[MAXN];
    memset(pre,-1,sizeof(pre));
    for(int i = 1;i<=cnt;i++){dis[i] = INF;ing[i] = false;}
    queue<int> Q;
    Q.push(s);
    ing[s] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        ing[u] = false;
        for(int i = 0;i<e[u].size();i++){
            if(e[u][i].capacity > 0){
                int v = e[u][i].to,cost = e[u][i].cost;
                if(dis[u] + cost < dis[v]){
                    dis[v] = dis[u] + cost;
                    pre[v] = u;
                    preve[v] = i;
                    if(!ing[v]){
                        ing[v] = true;
                        Q.push(v);
                    }
                }
            }
        }
    }
    return dis[t] != INF; //返回是否能得到整个路径的最短路径（是否还有增广路）
}

int MinCost(int s,int t,int cnt){
    int cost = 0;
    // 是否还存在增广路径
    while(SPFA(s,t,cnt)){
        int v = t,flow = INF;
        // 从底层回溯
        while(pre[v] != -1){
            int u = pre[v], i = preve[v];
            flow = min(flow,e[u][i].capacity);
            v = u;
        }
        v= t;
        // 更新残留网洛
        while(pre[v] != -1){
            int u = pre[v],i = preve[v];
            e[u][i].capacity -= flow;
            e[u][e[u][i].rev].capacity += flow;
            v = u;
        }
        cost += dis[t] * flow;
    }
    return cost;
}
int main(){
    int u,v,w;
    while(scanf("%d %d",&n,&m) && n != 0 || m != 0){
        for(int i = 0;i<=n;i++){
            e[i].clear();
        }
        for(int i = 1;i<=m;i++){
            cin >> u >> v >> w;
            // 添加4条边且流量capacit有= 1
            AddEdge(u,v,w,1); 
            AddEdge(v,u,w,1);
        }
    }
}