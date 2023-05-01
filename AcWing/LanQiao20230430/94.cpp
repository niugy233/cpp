/* 递归实现排列形枚举 */

#include <bits/stdc++.h>
using namespace std;

int N;
const int MAXN = 1e5;
vector<int> ans;
bool vis[MAXN];
void BFS(int deep){
    if(deep > N){
        for(int i =0;i<=ans.size()-1;i++){
            printf("%d ",ans[i]);
        }
        cout << endl;
    }
    // 从小到大枚举还未被选择过得数据
    for(int i = 1;i<=N;i++){
        if(!vis[i]){
            vis[i] = true;
            ans.push_back(i);
            BFS(deep+1);
            ans.pop_back();
            vis[i] = false;
        }
    }
    return ;
}

int main(){
    cin >> N;
    BFS(1);
}