// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1e5+10;
// int N,M,T;
// // i时刻j号店订单数量
// int cnt[MAXN][MAXN];
// // 记录各个店铺的优先级
// int prioritNum[MAXN];
// bool memory[MAXN];
// int Num;

// int main(){
//     cin >> N >> M >> T;
//     int a,b; //时刻a店铺b订单加1
//     for(int i = 1;i<=M;i++){
//         cin >> a >> b;
//         cnt[a][b]++;
//     }
//     // 循环遍历
//     for(int i = 1;i<=T;i++){
//         for(int j = 1;j <= N;j++){
//             //i时刻j号外卖店 没有订单 且优先级不为0
//             if(cnt[i][j] == 0){ if(!prioritNum[j]) prioritNum[j]--;}
//             //i时刻j号外卖店 有订单 优先级加2
//             else prioritNum[j] += 2;

//             // 判断是否在缓存区
//             // 不在缓存区
//             if(memory[j]){if(prioritNum[j] >= 5) memory[j] = true;}
//             // 在缓存区
//             else {if(prioritNum[j] <= 3) memory[j] = false;}
//         }
//     }
//     for(int i = 1;i<=N;i++){
//         if(memory[i]) Num++;
//     }
//     cout << Num << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1e5+10;
// int N ,M , T;
// bool A[MAXN];
// int B[MAXN];
// int cnt[MAXN];

// int main(){
//     cin >> N >> M >> T;
//     for(int i = 1;i<=M;i++){
//         int a,b;
//         cin >> a >> b;
//         B[b] = a;
//     }

//     // 计算各个位置的优先级
//     for(int j = 1;j<=T;j++){
//         for(int i = 1;i<=N;i++){
//             // i店铺j时刻有订单
//             if(B[i] == j){cnt[i] +=2 ;}
//             // i店铺j时刻无订单判断是否需要优先级-1
//             else{ if(cnt[i]) cnt[i]--;}
            
//             // 判断优先级决定是否进入缓存区
//             // 本来在缓存区优先级降低退出缓存区
//             if(cnt[i] <= 3 && A[i]){ A[i] = false;}
//             // 本来不在缓存区优先级增加进入缓存区
//             else if(cnt[i] > 5 && !A[i]){ A[i] = true;}
//         }
//     }
//     int num = 0;
//     for(int i = 1;i<=N;i++){
//         if(A[i]) num++;
//     }
//     cout << num << endl;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
typedef pair<int,int> PII;
PII order[MAXN];
int f[MAXN]; // 优先级
int last[MAXN];
bool sit[MAXN];
int N,M,T;

// 从小到大
// bool compare(int a,int b){ return a < b ?true:false;}
int main(){
    cin >> N >> M >> T;
    int a,b;
    for(int i = 1;i<=M;i++){
        int a,b;
        cin >> a >> b;
        // 时间a店铺b
        order[i].first = a,order[i].second = b; 
    }
    // 只需要按照时间排序
    sort(order+1,order+M+1);
    // M个订单处理M次
    for(int i = 1;i<=M;){
        int j = i;
        // 寻找与i订单不同的订单
        while(order[j] == order[i] && j <= M) j++;
        // 获取的是第i个数据
        int t = order[i].first;int id = order[i].second;
        int cnt = j - i; //cnt是同一家店铺同一时间的订单数量
        i = j; // 保证i一直处于为被访问的地方

        //计算店铺id的优先级
        f[id] -= t - last[id] - 1;
        if(f[id]  < 0) f[id] = 0;
        if(f[id] <= 3) sit[id] = false;

        f[id] += cnt * 2;
        if(f[id] > 5) sit[id] = true;

        last[id] = t;
    }

    //还需要处理最后一个时间节点的数据
    for(int i = 1;i<=N;i++){
        if(last[i] < T){
            // 这里不减1的原因是在这个循环处理的数据均是在最后时间节点无订单的数据
            f[i] -= T - last[i];
            if(f[i] <= 3) sit[i] = false;
        }
    }
    int cnt = 0;
    for(int i = 1;i<=N;i++){
        if(sit[i] == true) cnt++; 
    }

    cout << cnt << endl;
}