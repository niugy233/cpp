// /* P1088 [NOIP2004 普及组] 火星人 */
// #include <bits/stdc++.h>
// using namespace std;
// #define MAXN 10000
// int N = 0,Num = 0;

// int Date[MAXN],Date1[MAXN];
// int S[MAXN];
// int reslut[MAXN];

// bool cmp(int a,int b){
//     return a>b?true:false;
// }
// // 排序函数
// int Arrange(int num){
//     int result = 1;
//     for(int i = 1;i<=num;i++){
//         result *= i;
//     }
//     return result;
// }
// // 搜索函数
// int Serach(int tmp){
//     int left = 0,right = N -1;
//     int mid = (left + right + 1)/2;
//     while((right - left) > 1){
//         if(tmp < Date[mid]){
//             left = mid;
//         }
//         else if(tmp == Date[mid]){
//             return mid;
//         }
//         else{
//             right = mid;
//         }
//         mid = (left + right + 1) / 2;
//     }
//     if(tmp == Date[left]) return left;
//     else if( tmp == Date[right]) return right;
// }
// // 转换函数
// int Transform(){
//     int sum = 0;
//     for(int i = 0;i < N;i++){
//         // 余下需要解析的树木
//         int x = N - i;
//         // sort 默认是从小到大升序排列
//         sort(Date,Date + N,cmp);
//         int sit = Serach(S[i]);
//         sum += (x - sit - 1) * Arrange(x - 1);
//         // 相当于已经被选中消耗掉了
//         Date[sit] = 0;
//     }
//     return sum + 1;
// }

// void Pushback(int num){
//     // 这里换算时候需要-1（但是这个擦错是哪个地方的我还真没研究在Transform函数中sum返回时+1了）
//     num--;
//     for(int i = 0;i<N;i++){
//         sort(Date1,Date1 + N);
//         int n = Arrange(N - i - 1);
//         int sit = num / n;
//         cout << Date1[sit] << ' ';
//         Date1[sit] = N;
//         num -= n * (num / n);
//     }
// }
// int main(){
//     cin >> N >> Num;
//     memset(Date,0,sizeof(Date));
//     memset(S,0,sizeof(S));
//     for(int i = 0;i<N;i++){
//         cin >> S[i];
//         Date1[i] = Date[i] = S[i];
//     }
//     int num = Transform() + Num;
//     Pushback(num);
// }

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
int sum = 0;
int N,num;
int Date[MAXN];
bool Used[MAXN];
void DFS(int step){
    if(step >= N) {sum++;return;}
    for(int i = 0;i<N;i++){

        if(!Used[i]){
            Used[i] = true;
            DFS(step++);
            // 用完后归还
            Used[i] = false;
        }
    }
    return;
}
int main(){
    memset(Date,0,sizeof(Date));
    memset(Used,false,sizeof(Used));
    cin >> N >> num;
    for(int i = 0;i<N;i++){
        cin >> Date[i];
    }
}