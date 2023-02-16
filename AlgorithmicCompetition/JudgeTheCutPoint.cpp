/* 
    判断割点和割边
    无向图
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAXN 100
int dfn; //用于记录dfs的深度
int low[MAXN],num[MAXN]; // num记录访问的顺序，low记录能返回的最小的祖先
bool iscut[MAXN];
vector<int> G[MAXN];


// 节点u和父节点fa
void DFS(int u,int fa){
    low[u] = num[u] = ++dfn; // 在这里记录访问结点数量 
    // 所有结点从1开始舍弃掉0
    int child = 0; //记录孩子数量，说明这些孩子都可以返回到结点u
    for(int i = 1;i<=G[u].size();i++){
        int v = G[u][i];
        if(!num[v]){ //从未访问过结点v
            child++; // u结点下的孩子数量记录
            DFS(v,u); // 访问结点v
            low[u] = min(low[v],low[u]);
            if(low[u] > num[v] && u != 1){ //u != 1保证它不是根结点
                iscut[u] = true;
            }
        }
        // v结点已经访问过了触碰到该条支路的最后一个结点
        else if(num[v] < num[u] && v != fa){
            // 这里v！=fa保证u->v的边不是v -> u的边
            // 如果v = fa那么fa = v,u -> v 边就是 v -> u
            low[u] = min(low[u],num[v]); //吐过u作为叶结点还与其他结点相连，会通过循环逐渐找到最小值，返回时一定是最小的回退结点
        }
    }
    // 该判断针对根结点
    if(u == 1 && child >= 2){
        iscut[u] = true;
    }
}
int main(){
    // 图的输入邻接表
    int n;
    int u,v,w; //输入从u->v（无向图）
    cin >> n;
    for(int i = 0;i<MAXN;i++){
        G[i].clear();
    }
    // 忽略0从1开始
    int edgenum;
    cin >> edgenum;
    for(int i = 1;i<=edgenum;i++){
        cin >> u >> v;
        G[u].push_back(v);
    }  
    memset(num,0,sizeof(num));
    memset(low,0,sizeof(low));
    memset(iscut,false,sizeof(iscut));
    int dfn = 0;
    int ans = 0;
    DFS(1,-1); // 连通图可以通过一个结点到达任意结点
    for(int i = 1;i<=n;i++){
        if(iscut[i]){
            ans++;
        }
    }
    cout << ans << endl;
}