#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[15];
int result[15];

void DFS(int pos){
    if(pos > n){
        for(int i = 1;i<=n;i++){cout << result[i] << ' ';}
        cout << endl;
        return;
    }    
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            vis[i] = true;
            result[pos] = i;
            DFS(pos+1);
            vis[i] = false;
        }
    }
}
int main(){
    cin >> n;
    // for(int i = 1;i<=n;i++)
        DFS(1);
}