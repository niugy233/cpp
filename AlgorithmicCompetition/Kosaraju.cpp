#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005
vector<int> G[MAXN],RG[MAXN];
vector<int> S; //用于记录拓扑排序产生的结果用于接下来对反图的比较
int VIS[MAXN]; //记录被访问过的结点
int cnt,sccno[MAXN]; //cnt记录联通分量个数 sccno则是记录那些店被删除的
// 拓扑排序
void DFS1(int u){
    if(VIS[u]) return;
    VIS[u] = 1;
    for(int i = 0;i< G[u].size();i++){
        DFS1(G[u][i]);
    }
    S.push_back(u);
}

// 对反图做深度搜索
void DFS2(int u){
    if(sccno[u]) return;
    sccno[u] = cnt;
    for(int i = 0;i<RG[u].size();i++){
        DFS2(RG[u][i]);
    }
}
void kosaraju(int n){
    S.clear();
    cnt++; 
    memset(sccno,0,sizeof(sccno));
    memset(VIS,0,sizeof(VIS));
    for(int i = 1;i<=n;i++){
        DFS1(i);
    }
    for(int i = n-1;i>=0;i--){
        if(!sccno[i]) {cnt++; DFS2(S[i]);}
    }
}
int main(){
    // n是结点，m是边数
    int n,m,u,v;
    // 一个结点没有边也满足有向图强连通分量
    while(scanf("%d %d",&n,&m) && n != 0 || m != 0){
        for(int i = 0;i<n;i++){
            G[i].clear(); RG[i].clear();
        }
        for(int i = 0;i<m;i++){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    return 0;
}