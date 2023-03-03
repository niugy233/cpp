/* 地宫取宝 */

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int w[60][60];
int n,m,k;
// 四维数组代表从（1,1）到（i，J）时手中持有cnt个宝物最大价值为c的所有方案
int f[62][62][62][62];
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> w[i][j];
            // 要是不把拿了价值为0和没拿物品的情况分开的话，拿了价值为0 的情况由于if (cnt > 0 && k == a[i][j])这个判断条件， 会缺少一部分数值
            // 有可能存在宝贝价值为0的情况
            w[i][j]++;
        }
    }
    // 初始边界状态
    // 不选第一个物品
    f[1][1][0][0] = 1;
    // 选第一个物品的结果
    f[1][1][1][w[1][1]] = 1;
    // 计算能够刚好完成 ————手中有cnt个宝物且最大价值为c的全部可能相加
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int cnt = 0;cnt<=k;cnt++){
                for(int c = 0;c <= 14 ;c++){
                    // 不拿（i，j）点的宝物
                    f[i][j][cnt][c] = (f[i][j-1][cnt][c] + f[i][j][cnt][c]) % mod;
                    f[i][j][cnt][c] = (f[i-1][j][cnt][c] + f[i][j][cnt][c]) % mod;
                    // 如果拿走该点的宝物代表该的的宝物价值刚好是C也就是拿走该点的宝物该点的宝物的价值就是最大价值C
                    if(cnt > 0 && w[i][j] == c){
                        // 区分从上到下和从左到右
                        // 寻找手中有cnt-1个宝物的的全部可能方案相加
                        for(int x = 0;x<w[i][j];x++){
                            f[i][j][cnt][c] = (f[i][j-1][cnt-1][x] + f[i][j][cnt][c]) % mod;
                            f[i][j][cnt][c] = (f[i-1][j][cnt-1][x] + f[i][j][cnt][c]) % mod;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=13;i++){
        res = (res + f[n][m][k][i]) % mod;
    }
    cout << res << endl;
    return 0;
}