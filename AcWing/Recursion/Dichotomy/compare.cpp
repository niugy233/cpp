#include <bits/stdc++.h>
using namespace std;

typedef pair<int ,int > PII;
vector<PII> a,b;
int cnt = 0;
void compare(){
    for(int i = 0;i<170;i++){
        if(a[i].first != b[i].first || a[i].second != b[i].second){
            cout << a[i].first << ' ' << a[i].second << endl;
            cout << ' ' << b[i].first << ' ' << b[i].second << endl;
            cnt++;
        }
    }
}
int main(){
    for(int i = 0;i<170;i++){
        int c,d;
        cin >> c >> d;
        a.push_back({c,d});
    }
    for(int i = 0;i<170;i++){
        int c,d;
        cin >> c >> d;
        b.push_back({c,d});
    }
    compare();
    cout << cnt;
}