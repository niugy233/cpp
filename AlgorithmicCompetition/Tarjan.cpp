#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
int low[MAXN],num[MAXN],sccno[MAXN];
vector<int> G[MAXN];
int cnt; //记录scc数量
stack<int> ST;



void DFS(int u){
    low[u] = num[u] = 0;
    ST.push(u);
    for(int i = 0;i<G[u].size();i++){
        // 如果没有被访问过
        int v = G[u][i];
        if(!num[v]){ 
            DFS(v);
            low[u] = min(low[u],low[v]);
        }
        // v未出栈同时v结点被访问过 如果同时满足以上两点就是存在回退边
        // 未出栈代表结点u是某一SCC中的一个结点（不排除单独成立一个SCC）
        else if(!sccno[v]){ //结点u是叶子结点
            low[u] = min(low[u],num[v]);
        }
    }
    // 栈底的点事scc的祖先
    if(num[u] == low[u]){
        cnt++;
        while(1){
            ST.pop();
            int v = ST.top();
            if(u == v) break;
           
        }
    }
}

void Tarjan(int u){
    memset(low,0,sizeof(low));
    memset(num,0,sizeof(num));
    cnt = 0;
    DFS(1);
}
int main(){
    int n,m,u,v;

    while(scanf("%d %d",&n,&m) && n!=0 || m!= 0){
        for(int i = 0;i<=m;i++){
            G[i].clear();
        } 
        for(int i = 1;i<=n;i++){
            cin >> u >> v;
            G[u].push_back(v);
        }       
    }
}