/* 暴力枚举出9
9
个数的全排列，然后用一个长度为9
9
的数组保存全排列的结果
从全排列的结果中用两重循环暴力分解出三段，形如下图，通过 i,j

 将一个排列分割，每段代表一个数

验证枚举出来的三个数是否满足题干条件，若满足则计数 */

#include <bits/stdc++.h>
using namespace std;
const int N = 10;

int target;  // 题目给出的目标数
int num[N];  // 保存全排列的结果
bool used[N];  // 生成全排列过程中标记是否使用过
int cnt;  // 计数，最后输出的结果

// 计算结果是否符合要求
int calc(int l,int r){
    int res = 0;
    for(int i = l;i<=r;i++){
        res = res * 10 + num[i];
    }
    return res;
}
// 利用深度搜索求全排列
void DFS(int deep){
    if(deep == 10){
        for(int i = 1;i<=9;i++){
            for(int j = i+1;j<=9;j++){
                int a = calc(1,i);
                int b = calc(i+1,j);
                int c = calc(j+1,9);
                if(target * c == a * c + b){
                    cnt++;
                }   
            }
        }              
        return;
    }
    // 从1开始
    for(int i = 1;i<=9;i++){
        if(!used[i]){
            num[deep] = i;
            used[i] = true;
            DFS(deep+1);
            used[i] = false;
        }
    }
}
int main(){
    memset(used,false,sizeof(used));
    cin >> target;
    DFS(1);
    cout << cnt;
}