/* 树形DP简单难度 */

#include <iostream>
#include <vector>
using namespace std;
#define MAXN 6005
int value[MAXN],father[MAXN],dp[MAXN][2];
vector<int> tree[MAXN];


void DFS(int u){ //u代表当前节点u
    dp[u][0] = 0; //不选择当前节点
    dp[u][1] = value[u]; //选择当前节点

    for(int i = 0;i<tree[u].size();i++){
        int son = tree[u][i];
        DFS(son);
        dp[u][0] += max(dp[son][0],dp[son][1]); //子节点可选可不选
        dp[u][1] += dp[u][0];
    }
}
int main(){
    int N;
    cin >> N;
    //初始化
    for(int i = 1;i<=N;i++){
        cin >> value[i];
        tree[i].clear(); //调用clear之后, vector的尺寸(size)将变成zero. 但它的容量(capacity)却并不发生变化, vector本身并不释放任何内存.
        father[i] = -1;
    }
    int x,y;
    while(1){
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        tree[y].push_back(x);
        father[x] = y; //x的父节点是y
    }
    int t = 1;
    while(father[t] != -1){ //查找树的根节点 //只有根节点的父节点为-1
        t = father[t];
    }
    DFS(t);
    cout << max(dp[N][0],dp[N][1]) << endl;
    return 0;

}