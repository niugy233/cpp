/* 归并排序 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

void merage(int num[],int l,int r){
    int mid = (l+r) >> 1;
    int count = (r-l)+1;
    int i = l;int j = mid+1;
    int tmpe[MAXN];
    for(int k = l;k < count+l;k++){
        // 最关键的判断在这里需考虑一边已经越界了
        if(num[i] <= num[j] && i <= mid || j > r)
            tmpe[k] = num[i++];
        else   
            tmpe[k] = num[j++];
    }
    for(int k = l;k < count + l;k++){
        num[k] = tmpe[k];
    }
    return;
}

void solve(int num[],int l,int r){
    if(l+1>r) return;
    int mid = (l+r) >> 1;
    solve(num,l,mid);
    solve(num,mid+1,r);

    merage(num,l,r);
    return;
}
int main(){
    int num[MAXN];
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> num[i];
    }    

    solve(num,1,n);
    for(int i = 1;i<=n;i++){
        cout << num[i] << ' ';
    }
}