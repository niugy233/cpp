#include <bits/stdc++.h>
using namespace std;

#define Num 103
int S[Num];//并查集
struct Edge{int u,v,w;} edge[Num * Num];
bool cmp(Edge a, Edge b){return a.w < b.w;}
int find(int u){ return S[u] == u ? u : find(S[u]);} //查询并查集并返回定点
int n,m;

int Kruskal(){
    int ans;
    // 初始化开始时每个每个结点的集合属于自己
    for(int i = 1;i<=n;i++){
        S[i] = i;
    }
    sort(edge,edge+m,cmp);
    // 将边排列后安早从小到大的顺序取出
    for(int i= 0;i<m;i++){
        int a = find(edge[i].u); // 边的前端点属于那个集
        int b = find(edge[i].v); // 变得厚街店属于那个集
        if(a == b)               // 如果相等形成一个圈丢弃这个边
            continue;
        // 反之
        S[b] = a; //将v的头b改为u的头a
        ans += edge[i].w;
    }
    return ans;
}
int main(){
    int u,v,w;
    while(scanf("%d %d", &n,&m) && n != 0 || m != 0){
        for(int i = 0;i<m;i++){
            cin >> u >> v >> w;
            edge[i].u = u;
            edge[i].v = v;
            edge[i].w = w;
        }
    }
}