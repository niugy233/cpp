/* 
小鱼的数字游戏 | P1427
题目描述
小鱼最近被要求参加一个数字游戏，要求它把看到的一串数字 a_ia 
i
​
 （长度不一定，以 00 结束），记住了然后反着念出来（表示结束的数字 00 就不要念出来了）。
 这对小鱼的那点记忆力来说实在是太难了，
 你也不想想小鱼的整个脑袋才多大，其中一部分还是好吃的肉！所以请你帮小鱼编程解决这个问题
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 101
int num[MAXN];

int returnNum(int i){
    if(num[i] == 0) return num[i];
    int re = returnNum(i+1);
    cout << num[i] << ' ';
    return num[i];
}
int main(){
    cin >> num[0];
    for(int i = 0;num[i] != 0;){
        i++;
        cin >> num[i];
    }
    returnNum(0);
}