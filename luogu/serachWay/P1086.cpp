/* P1086 [NOIP2004 普及组] 花生采摘 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int line,column,timeing;
int Field[MAXN][MAXN];
int sum = 0;
// 一次存储最大值
int Max[MAXN];
int Sitl[MAXN],Sitc[MAXN];


void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    return;
}
void Quick_Sort(int begin, int end){
    if(begin > end)
        return;
    int tmp = Max[begin];
    int i = begin;
    int j = end;
    while(i != j){
        while(Max[j] <= tmp && j > i)
            j--;
        while(Max[i] >= tmp && j > i)
            i++;
        if(j > i){
            swap(Max[i], Max[j]);
            swap(Sitl[i],Sitl[j]);
            swap(Sitc[i],Sitc[j]);
        }
    }
    swap(Max[begin],Max[i]);
    swap(Sitl[begin],Sitl[i]);
    swap(Sitc[begin],Sitc[i]);
    Quick_Sort(begin, i-1);
    Quick_Sort(i+1, end);
}

// 返回收集到的数字数目
int FindMax(){
    int k = 0;
    for(int i = 1;i<=line;i++){
        for(int j = 1;j<=column;j++){
            if(Field[i][j] != 0){
                k++;
                Sitl[k] = i;Sitc[k] = j;
                Max[k] = Field[i][j];
            }
        }
    }
    return k;
}

// void Pick(int lnow,int cnow,int timenow){
//     int l,c;
//     // FindMax(l,c);
//     if(Field[l][c] == 0) return;
//     timenow -= ((abs(lnow - l) + abs(cnow - c)) + 1);
//     if((timenow - c) >= 0 ){
//         sum += Field[l][c];
//         Pick(l,c,timenow);
//     }
//     return;
// }

void Pick(){
    // timenow需要抛去进入哈出去的耗时
    int k = 1;
    int l = Sitl[k], c = Sitc[k],timenow = timeing;
    timenow -= (l + 1); //挖萝卜也需要时间
    // 等于0是刚好耗时这么久
    while(timenow - l >= 0 && Max[k] != 0){
        sum += Max[k];
        k++;
        l = Sitl[k],c = Sitc[k];
        timenow -= ((abs(Sitl[k -1] - l) + abs(Sitc[k -1] - c)) + 1);
    }
}

int main(){
    cin >> line >> column >> timeing;
    for(int i = 1;i<=line;i++){
        for(int j = 1;j <= column;j++){
            cin >> Field[i][j];
        }
    }
    Quick_Sort(1,FindMax());
    Pick();
    cout << sum << endl;
}