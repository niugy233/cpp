#include <bits/stdc++.h>
using namespace std;

string str1,str2;
int ans = 0;

void turn(int x){
    if(str2[x] == '*') str2[x] = 'o';
    else str2[x] = '*';
    if(str2[x+1] == '*') str2[x+1] = 'o';
    else str2[x+1] = '*';
}
bool compare(int x){
    if(str1[x] != str2[x]) return false;
    return true;
}

void solve(){
    for (int i = 0; i < str1.size(); i++){
        if(!compare(i)){
            turn(i);
            ans++;
        }
    }
    cout << ans;
}
int main(){
    cin >> str1 >> str2;
    solve();
}