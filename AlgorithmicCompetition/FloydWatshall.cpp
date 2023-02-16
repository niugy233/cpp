/* 弗洛伊德算法存储使用邻接矩阵 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200
#define INF 1e6
int n,m;
/* 关键在于如何处理局部最优解与全局最优 */
int G[MAXN][MAXN];

void Floyd(){
    int s = 1;
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            if(G[i][k] == INF) break;
            for(int j = 1;j<=n;j++){
                // G[i][j] 代表从i到j的最小值
                // 更新图
                if(G[i][j] > G[i][k] + G[k][j]){
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
    cout << G[1][n];
}
int main(){
    int u,v,w;
    while(scanf("%d %d",&n,&m) && n != 0 || m != 0){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                G[i][j] = INF;
            }
        }    
        for(int i = 0;i<m;i++){
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = w;
        }
    }

}