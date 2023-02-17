#include <bits/stdc++.h>
using namespace std;

#define MAXN 30
int result[MAXN];
bool vis[MAXN];
int n,m;


void DFS(int deep,int start){
    if(deep > m){
        for(int i = 1;i<=m;i++){
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = start;i<=n;i++){
        if(!vis[i]){
            result[deep] = i;
            vis[i] = true;
            DFS(deep+1,i+1);
            vis[i] = false;
        }
    }
}


int main(){
    cin >> n >> m;
    memset(vis,false,sizeof(vis));
    DFS(1,1);
}