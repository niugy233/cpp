#include <bits/stdc++.h>
using namespace std;

// 记录每次换购的饮料数目
int num=0;;
// 记录每次换购后总的饮料数目
int reminder = 0;
int cnt;
void solve(){
    if(reminder < 3){
        cnt += num;
        return;
    }
    cnt += num;
    num = reminder / 3;
    reminder = reminder / 3 + reminder % 3;

    solve();
    return;
}
int main(){
    cin >> num;
    reminder = num;
    solve();
    cout << cnt;
}