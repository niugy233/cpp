/* P1036 [NOIP2002 普及组] 选数 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int N,K;
// 界限
int sum = 0;
int result;
// 筛选质数
bool FilterPrimeNumbers(int num){
    for(int i = 2;i<num/2;i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
// 初始l = 0,k = 0
void SelectNum(int l,int k,int num[]){
    if(k >= K){ // 控制深度
        if(FilterPrimeNumbers(sum)) result++; 
        sum -= num[l-1];
        k--;
        return;
    }
    for(int i = l;i < (N - (K - K));i++){
        sum += num[i];
        SelectNum(i+1,k+1,num);
    }
    sum -= num[l-1];
    return;
}
int main(){
    int num[MAXN];
    cin >> N >> K;
    for(int i = 0;i<N;i++){
        cin >> num[i];
    }
    SelectNum(0,0,num);
    cout << result << endl;
}