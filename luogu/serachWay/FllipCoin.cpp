
/*题目描述(入门级别)
在桌面上有一排硬币，共NN枚，每一枚硬币均为正面朝上。
现在要把所有的硬币翻转成反面朝上，规则是每次可翻转任意N-1
N−1枚硬币（正面向上的被翻转为反面向上，反之亦然）。
求一个最短的操作序列（将每次翻转N-1枚硬币成为一次操作）。
  */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
int N;
int main(){
    int coin[MAXN]; //1代表正面，0代表反面
    memset(coin,0,sizeof(coin));
    cin >> N;
    cout << N << endl;
    while(N>100 || N <0 && N%2 != 0)
        cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(i!=j){
                if(coin[j] == 0){
                    coin[j] = 1;
                }
                else{
                    coin[j] = 0;
                }
            }
        }
            for(int j = 0;j<N;j++){
                cout << coin[j];
            }
            cout << endl;
    }
}
