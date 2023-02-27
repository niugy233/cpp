#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100005;
int sum[MAXN];
int cnt[MAXN];
long long ans = 0;
int main(){
    int N,K;
    memset(sum,0,sizeof(sum));
    memset(cnt,0,sizeof(cnt));
    cin >> N >> K;
    // 得到全部的sum
    for(int i = 1;i<=N;i++){
        int a;
        cin >> a;
        sum[i] = (sum[i - 1] + a) % K;
        // 遇到两个相同的余数时就代表
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    // 将
    cout << ans+cnt[0] << endl;
}