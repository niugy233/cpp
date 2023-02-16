/* 队列加上邻接表的方式 */

#include <bits/stdc++.h>
using namespace std;

#define INF 1e5
#define MAXN 100
struct edge{
    int from,to,w;
    edge(int a,int b, int c){from = a,to = b,w = c;}
};
int pre[MAXN]; //记录前置结点
vector<edge> e[MAXN]; //存储边的关系

void SPFA(int n){
    int s = 1;
    int dis[MAXN];
    bool ing[MAXN]; //是否在队列中
    for(int i = 1;i<=n;i++){dis[i] = INF;ing[i] = false;} //距离dis数组初始化
    dis[1] = 0;//自己到自己距离为0
    ing[1] = true;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop(); //队头出队
        ing[u] = false;
        for(int i = 0;i<e[u].size();i++){
            int v = e[u][i].to; int w = e[u][i].w;
            //是否更新结点
            if(dis[v] > dis[u] + w){ //现在从u到结点1的距离 > 现在从v到1的距离 + 从u到v的距离
                dis[v] = dis[u] + w;
                pre[v] = v;
                if(!ing[v]){
                    Q.push(v); //加入队列
                    ing[v] = true;
                }
            }
        }
    }
}
int main(){
    int n,m,u,v,w;
    while(scanf("%d %d",&n, &m) && n != 0 || m != 0){
        for(int i = 1;i<=n;i++)
            e[i].clear();
        for(int i = 1;i<=m;i++){
            cin >> u >> v >> w;
            e[u].push_back(edge(u,v,w));
            e[v].push_back(edge(v,u,w));
        }
    }
}