// 机器人爬楼二分法求解/递推
#include <bits/stdc++.h>
using namespace std;

int N;
int H[100005];

// 模拟整个过程
long long judge(long long E){
    for(int i = 1;i<=N;i++){
        E = 2*E - H[i];
        if(E < 0){
            return E;
        }
        else if(E > 1e5)
        return true;
    }
    return E;
}

void solve(){
    int l = 0,r = 1e5 + 1;
    int mid = 0;
    while(r - l > 1){
        mid = (r + l)>>1;
        long long E = judge(mid);
        // 处理边界问题
        if(E < 0)
            l = mid;
        else    
            r = mid;
    }
    cout << r;
}

int main(){
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> H[i];
    }
    solve();
}