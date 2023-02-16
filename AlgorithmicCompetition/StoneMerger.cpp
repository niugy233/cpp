#include <iostream>
using namespace std;
#define MAXN 301

const int INF = 1 << 30;
int sum[MAXN] = {0};
int dp[MAXN][MAXN];
int n;
int s[MAXN][MAXN];

int Minval(){
    int len;
    for(int i = 1;i <= n;i++){
        dp[i][i] = 0;
        s[i][i] = i;
    }
    for(len = 1;len < n;len++){ //len石i和j之间的长度，最短石1最长石n-1所已len<n
        for(int i = 1;i<=n-len;i++){
            int j = i + len;
            dp[i][j] = INF;
            for(int k = s[i][j-1];k<=s[i+1][j];k++){
                if(dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1] < dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1];
                    s[i][j] = k;
                }
            }
        }
    }
    return dp[1][n];
}
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        sum[i] += sum[i-1] + x;
    }
    cout << Minval() << endl;
}