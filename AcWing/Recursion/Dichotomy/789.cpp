#include <bits/stdc++.h>
using namespace std;

typedef pair<int ,int > PII;
int num[10005];
vector<PII> ans;
bool haveans = false;

void find(int sit){
    int l = sit,r = sit;
    for(;num[sit] == num[l];l--){
    }
    while(1){
        if(num[r] != num[sit])
            break;
        r++;
    }
    ans.push_back({l + 1,r - 1});    
}
// 二分查找
void search(int n,int a){
    int i = 0,j = n - 1;
    int sit = (i + j) / 2;
    while(n--){
        if(num[sit] == a){
            find(sit);
            haveans = true;
            break;
        }
        else if(num[sit] > a){
            j = sit - 1;
            sit = i + ((j - i) /2);

        }
        else if(num[sit] < a){
            i = sit + 1;
            sit = i + ((j - i) /2);
        }
    }
    if(!haveans){
        cout << "-1 -1" << endl;
    }
    return;
}

int main(){
    int n,q;
    cin >> n >> q;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    while(q--){
        int target;
        cin >> target;
        search(n,target);
    }
    for(auto res:ans){ cout << res.first << ' ' << res.second << endl;}
}