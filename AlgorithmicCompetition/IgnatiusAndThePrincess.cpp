// /* 递归得到全部数据 */


// 1.用递归
// #include <iostream>
// using namespace std;

// int part(int n,int m){
//     if(n == 1 || m == 1){ return 1;}
//     else if(n == m){ return 1 + part(n-1,m);}
//     else if(n > m){ return part(n,n);}
//     else {return part(n-m,m) + part(n,m-1);} //程序复杂度翻倍
// }

// int main(){
//     int n,m;
//     cin >> n >> m;
//     cout << part(n,m) << endl;
// }

// 2.用动态规划

// #include <iostream>
// using namespace std;
// #define MAXN 100
// int dp[MAXN +1][MAXN +1];

// void part(int n,int m){
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             if(n == 1 || m == 1) dp[i][j] = 1;
//             else if(n == m) dp[i][j] = 1 + dp[i-1][j];
//             else if(n < m) dp[i][j] = dp[i][i];
//             else dp[i][j] = dp[i-j][j] + dp[i][j-1];
//         }
//     }
// }
// int main(){
//     int n,m;
//     cin >> n >> m;
// }

/* 普通母函数d */
#include <iostream>
using namespace std;
#define MAXN 100
int c1[MAXN],c2[MAXN];

void part(){
    int i,j,k;

    for(int i = 0;i<=MAXN;i++){
        c1[i] = 1;c2[i] = 0;
    }
    for(int  k = 2;k<MAXN;k++){
        for(int i = 0;i<MAXN;i++){
            for(int j = 0;i+k < MAXN;j += k){
                c1[i+j] += c1[i];
            }
        }
        for(int i = 0;i<MAXN;i++){
            c1[i] = c2[i];c2[i] = 0;
        }
    }
}
int main(){
}