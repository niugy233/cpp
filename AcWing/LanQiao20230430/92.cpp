/* 递归输出组合型枚举 */

#include <bits/stdc++.h>
using namespace std;

int N;
const int MAXN = 1e5;
// int ans[MAXN];
vector<int> ans;
int k = 0;

void print(){
    for(int i = 0;i<ans.size()-1;i++){
        cout << ans[i] << ' ';
    }
    cout << ans[ans.size()-1] << endl;
}
void BFS(int num){
    if(num > N){return;}

    for(int i = num;i<=N;i++){
        ans.push_back(i);
        print();
        BFS(i+1);
        ans.pop_back();
    }

}
int main(){
    cout << endl;
    cin >> N;
    BFS(1);
}