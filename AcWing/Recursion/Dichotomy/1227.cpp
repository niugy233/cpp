#include <bits/stdc++.h>
using namespace std;

struct CHOC{
    int H,W;
};
int N,K;

vector<CHOC> chocolate; 
// 能否分配成功
// X*X的正方形巧克力
int division(int x){
    int cnt = 0;
    for(int i = 0;i<N;i++){
        int h = chocolate[i].H,w = chocolate[i].W;
        while(h - x >= 0){
            h-=x;
            w = chocolate[i].W;
            while (w - x >= 0){
                w-=x;
                cnt++;
            }
        }
    }
    return cnt;
}
// 二分法枚举结果
void solve(){
    int l = 0,r = 5 * 1e6;
    int mid;
    while (l+1 < r){
        mid = (l +r) >> 1;
        if(division(mid) < K)
            r = mid;
        else 
            l = mid;
    }
    cout << l; 
    return;
}
int main(){
    cin >> N >> K;
    for(int i = 0;i<N;i++){
        int a,b;
        cin >>a>>b;
        chocolate.push_back({a,b});
    }
    solve();
    return 0;
}