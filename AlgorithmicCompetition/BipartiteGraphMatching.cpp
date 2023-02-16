#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
int G[MAXN][MAXN];
int match[MAXN], reserve_boy[MAXN];
int k,NumGirl,NumBoy;


//返回是否能找到合适的
bool DFS(int x){
    for(int i = 1;i<=NumBoy;i++){
        if(!reserve_boy[i] && G[x][i]){
            reserve_boy[i] = 1;
            if(!match[i] || DFS(match[i])){
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d",&k) != EOF && k){
        cin >> NumGirl >> NumBoy;
        memset(G,0,sizeof(G));
        memset(match,0,sizeof(match));
        for(int i = 1;i<=k;i++){
            int a,b;
            cin >> a >> b;
            G[a][b] = 1;
        }
    }
    int sum = 0;
    for(int i = 1;i<=NumGirl;i++){
        memset(reserve_boy,0,sizeof(reserve_boy));
        if(DFS(i)) sum++; 
    }
}