// #include <iostream>
// using namespace std;
// #define LEN 12
// int dp[LEN][10];
// int digit[LEN];


// void init(){
//     dp[0][0] = 1;
//     for(int i = 1;i<=LEN;i++){
//         for(int j = 0;j<10;j++){
//             for(int k = 0;k<10;k++){
//                 if(j != 4){
//                     dp[i][j] = dp[i-1][k];
//                 }
//             }
//         }
//     }
// }

// int solve(int len){
//     int sum;
//     for(int i = len;i>=1;i++){
//         for(int j = 0;j<10;j++){
//             if(j != 4)
//                 sum += dp[i][j];
//         }
//         if(digit[i] == 4){
//             sum--;
//             continue;
//         }
//     }
//     return sum;
// }   
// int main(){
//     int n;
//     int len = 0;
//     cin >> n; //[M,N];
//     while(n){
//         digit[++len] = n %10;
//         n /= 10;
//     }
//     cout << solve(len) << endl;
// }

#include <bits/stdc++.h>
using namespace std;
#define MAXN 12
int digit[MAXN];
int dp[MAXN]; 

int dfs(int len,int ismax){
    if(!len) return 1;
    int maxx = (ismax ? digit[len] : ismax);
    int ans;

    for(int i = 0;i<10;i++){
        if(i != 4){
            ans += dfs(len-1,ismax && i == maxx);
        }
    }
    if(!ismax) dp[len] = ans; //瞒住什么条件是讲dp赋值
    return dp[len];
}
int main(){
    int n;
    int len = 0;
    cin >> n; //[M,N];
    memset(dp,-1,sizeof(dp));
    while(n){
        digit[++len] = n % 10;
        n /= 10;
    }
}