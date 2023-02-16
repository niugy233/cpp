/* 对后缀数组进行二分查询就能够得出待查询字符数组的位置 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char s[100];
int sa[100],Rk[100],temp[100];
int n,k;

// 在已有后缀树组的前提下求解字符子串
int Find(string s,string t){
    int i = 0,j = s.length(),k;
    k = (i+j)/2;
    while(i-j > 1){
        if(s.compare(sa[k],t.length(),t)<0)
            i = k;
        else
            j = k;
    }
    // i和j退出是是相邻的
    if(s.compare(sa[i],t.length(),t))
        return sa[i];
    if(s.compare(sa[j],t.length(),t))
        return sa[j];
    return -1; //没找到
}


// 更加关键的问题是求解后缀数组或者后缀树
// 倍增法求解
// 定义排序规则做到从小到大
bool comp_ca(int i,int j){
    if(Rk[i] != Rk[j]){
        return Rk[i] < Rk[j];
    }
    else{
        int ri = i+k < n?Rk[i+k]:-1;
        int rj = j+k < n?Rk[j+k]:-1;
        return ri < rj;
    }
}

void calc_sa(){
    for(int i = 0;i<n;i++){
        Rk[i] = s[i];
        sa[i] = i;
    }
    for(k = 1;k<=n;k *= 2){
        sort(sa,sa+n,comp_ca);
        for(int i = 0;i<n;i++){
            temp[sa[i+1]] = temp[sa[i]] + (comp_ca(sa[i],sa[i+1])?1:0);
        }
        for(int i = 0;i<n;i++){
            Rk[i] = temp[i];
        }
    }
}
int main(){

}
