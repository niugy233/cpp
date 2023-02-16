

#include <bits/stdc++.h>
using namespace std;

int n;
int result[20];
bool vis[20];

void DFS(int pos,int start,int tar){
    if(pos > tar){
        for(int i = 1;i<=tar;i++) {cout << result[i] << ' ';}
        cout << endl;
        return;
    }
    for(int i = start;i<=n;i++){
        if(!vis[i]){
            result[pos] = i;
            vis[i] = true;
            DFS(pos+1,i,tar);
            vis[i] = false;
        }
    }
}
int main(){
    cin >> n;
    cout << endl;
    for(int i = 1;i<=n;i++){
        DFS(1,1,i);
    }
}
