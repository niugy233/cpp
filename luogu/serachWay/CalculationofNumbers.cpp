/* [NOIP2001 普及组] 数的计算 | P1028
题目描述
给出自然数 nn，要求按如下方式构造数列：

只有一个数字 nn 的数列是一个合法的数列。
在一个合法的数列的末尾加入一个自然数，但是这个自然数不能超过该数列最后一项的一半，可以得到一个新的合法数列。
请你求出，一共有多少个合法的数列。两个合法数列 a, ba,b 不同当且仅当两数列长度不同或存在一个正整数 i \leq |a|i≤∣a∣，使得 a_i \neq b_ia 
i
​
 ≠b 
i */
#include <bits/stdc++.h>
using namespace std;
int num,sum;
// 递归但是超时间
void calculate(int date){
    if(date < 1) return; 
    for(int i = date/2;i>=1;i--){
        calculate(i);
    }
    sum++;
    return;
}
// 下面的递归方式不超时间
int result;
void sum1(int date){
    for(int i = 1;i <= date/2;i++){
        result++;
        sum1(i);
    }
}
int main(){
    cin >> num;
    sum1(num);
    cout << result+1;
}