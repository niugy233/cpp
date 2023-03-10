/* 该程序无法运行文档名称不符合规范 */

/* 使用前缀和的方式求解递增三元组 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N;
int num[3][MAXN];
int cntA[MAXN],cntC[MAXN];
int prefixSUmA[MAXN],prefixSUmC[MAXN];

long long cnt = 0;

int main(){
    cin >> N;
    for(int i = 0;i<3;i++){
        for(int j = 1;j<=N;j++){
            cin >> num[i][j];
            num[i][j]++; //保证数组中最小的数是1
        }
    }
// 计算num[i][j]在A C 数组中的数量
    for(int i = 1;i<=N;i++){
        cntA[num[0][i]]++;
        cntC[num[0][i]]++;
    }
// 计算前缀和
    for(int i = 1;i<N;i++){
        // <=i           == i          <i
        prefixSUmA[i] = cntA[i] + prefixSUmA[i-1];
        prefixSUmC[i] = cntC[i] + prefixSUmC[i-1];
    }

    // 枚举数列B
    for(int i = 1;i<=N;i++){
        long long j = prefixSUmA[num[1][i] - 1];
        long long k = prefixSUmC[num[1][i] + 1];
        if(j >= 1 && k <= N){
            cnt += j*(N-k);
        }
    }
}