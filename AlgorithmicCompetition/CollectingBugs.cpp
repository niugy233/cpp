
/* 
    收集bugs
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100
double dp[MAXN][MAXN];
int main(){
    int n,s;
    cin >> n >> s;
    dp[n][s] = 0.0; //表示发现n种病毒属于s个子系统要达到目标还需要0天
    for(int i = n;i >= 0;i--){
        for(int j = s; j >= 0 ;j--){
            dp[i][j] = (n*s + (n-i) * j * dp[i+1][j] + i * (s-j) * dp[i][j+1] + (n-i) * (s-j) * dp[i+1][j+1])/(n*s - i * j);
        }
    }
}