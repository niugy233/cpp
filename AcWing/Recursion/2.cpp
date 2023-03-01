/* 01背包问题 */
#include <bits/stdc++.h>
using namespace std;

#define N 1005
int f[N][N];
int v[N],w[N];
int n,m;

int main(){
    cin >> n >> m;
    memset(f,0,sizeof(f));
    for(int i = 1;i<=n;i++) cin >> v[i] >> w[i];

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            // 选与不选
            f[i][j] = f[i-1][j];
            if(j>=v[i]){
                f[i][j] = max(f[i][j],f[i-1][j-v[i]] + w[i]);
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=m;i++){
        res = max(res,f[n][i]);
    }
    cout << res << endl;
}