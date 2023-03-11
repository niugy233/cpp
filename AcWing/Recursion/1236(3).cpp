/* 用双指针的方式求解 */
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int num[3][MAXN];
int N;
long long cnt = 0;
int main(){
    cin >> N;
    for(int i = 0;i<3;i++){
        for(int j = 1;j<=N;j++){
            cin >> num[i][j];
        }
        // 从1到0
        sort(num[i]+1,num[i]+N+1);
    }
    // 双指针法
    // 枚举数组B
    int j = 1,k = 1;
    for(int i = 1;i<=N;i++){
        // 由于三个数组均为有序数组可以用双指针的方式求解
        // 最主要的是B[i] 对两个数组的判断能够影响到对B[i+1]的判断
        while(j <= N && num[0][j] < num[1][i]) j++;
        while(k <= N && num[2][k] <= num[1][i]) k++;
        cnt +=  (long long) (j-1) * (N-k+1);
    }
    cout << cnt << endl;
}