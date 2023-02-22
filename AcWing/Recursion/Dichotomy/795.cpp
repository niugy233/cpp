#include <bits/stdc++.h>
using namespace std;

// int num[100005];
// 前缀和数组
long long sum[100005];

int main(){
    int n,m;
    cin >> n >> m;
    memset(sum,0,sizeof(sum));
    // memset(num,0,sizeof(num));
    for(int i = 1;i<=n;i++){
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    while(m--){
        int i,j;
        cin >> i >> j;
        cout << sum[j]- sum[i - 1] << endl;
    }
}