// 方法1暴力枚举
// 也可以将'+' '-' 替换成1,0方便操作
// 暴力枚举的是方案而不是开关
#include <bits/stdc++.h>
using namespace std;

typedef pair<int , int> PII;
#define MAXN 6
#define INF 1e6
char ch[MAXN][MAXN];
int ans = INF;

typedef pair<int,int> PII;

char back_up[MAXN][MAXN];

int get(int i,int j){
    return 4 * (i-1) + j - 1;
}
// void turn_all(int i,int j){
//     for(int k = 1;i<=4;i++){
//         if(ch[i][k] == '+' && k != i)
//             ch[i][k] = '-';
//         else if(k != i)
//             ch[i][k] = '+';
//         if(ch[k][j] == '-' && k != j)
//             ch[k][j] = '+';
//         else if(k != j)
//             ch[k][j] = '-';
//     }
//     if(ch[i][j] == '+')
//         ch[i][j] = '-';
//     else
//         ch[i][j] = '+';
// }

// 改变状态函数
void turn_one(int x,int y)
{
    if(ch[x][y]=='+') ch[x][y]='-';
    else ch[x][y]='+';
}

void turn_all(int x,int y)
{
    for(int i=1;i<=4;i++)
    {
        turn_one(x,i);
        turn_one(i,y);
    }
    turn_one(x,y);

}

int main(){
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=4;j++){
            cin >> ch[i][j];
        }
    }
    vector<PII> res;
    // op取从1到2的16次方分别对应2的16次方种情况
    for(int op = 0;op < (1 << 16);op++){

        memcpy(ch,back_up,sizeof(ch));
        // tmpe用于暂时存储改变的
        vector<PII> tmpe;
        // 
        for(int i = 1;i<=4;i++){
            for(int j = 1;j<=4;j++){
                // op向后移位get(i,j)位，1代表改变i行j列
                if(op >> get(i,j) & 1){
                    turn_all(i,j);
                    tmpe.push_back({i,j});
                }
            }
        }
        // 判断是否能够满足题设
        bool have_pass = true;
        for(int i = 1;i<=4;i++){
            for(int j = 1;j<=4;j++){
                if(ch[i][j] == '+') have_pass = false; break;
            }
        }

        if(have_pass){
            //如果方案为空或者他的操作数大于我们刚存好的新的方案，那么就修改它
            if(res.empty()||res.size()>tmpe.size()) res=tmpe; 
        }
        have_pass = true;
        memcpy(back_up,ch,sizeof(ch));
    }

    cout << res.size() << endl;
    for(auto op : res) cout << op.first << ' '<< op.second << endl;
    return 0;
}