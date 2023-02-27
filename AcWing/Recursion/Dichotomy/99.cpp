#include <bits/stdc++.h>
using namespace std;

// 定义数组长度必须使用静态常量
const int M = 5010;
// 堆存储和栈存储
int g[M][M];
int N,R;

int main(){
    // c++局部变量可以和全局变量命名重复函数内优先调用局部变量
    int N;
    memset(g,0,sizeof(g));
    cin >> N >> R;
    // 防止出界
    int n,m;
    if(N >= R)
        n = R,m = R;
    else{
        int res = 0;
        for(int i = 0,x,y,w;i<N;i++){
            cin >> x >> y >> w;
            x++;y++;//数组从1开始计数
            res += w;   
        }
        cout << res;
        return 0;
    }
    for(int i = 0,x,y,w;i<N;i++){
        cin >> x >> y >> w;
        x++;y++;//数组从1开始计数
        n = max(n,x),m = max(m,y);
        g[x][y] += w;    
    }
    // 计算二维前缀和
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            g[i][j] += g[i- 1][j] + g[i][j - 1] - g[i-1][j-1];
        }
    }
    int res = 0;
    // 利用二维前缀和数组计算
    for(int i = R;i <= n;i++){
        for(int j = R;j<=m;j++){
            res = max(res,g[i][j] - g[i-R][j] - g[i][j-R] + g[i-R][j-R]);
        }
    }
    cout << res << endl;
    return 0;
}