#include <bits/stdc++.h>
using namespace std;
int N; //数组内元素的个数

int Binary_search(int a[],int target){
    // 注意左右边界的选取
    int l = -1,r = N;
    int mid;
    while(l+1 < r){
        mid = (l+r) >> 1;
        // 需要讨论a[mid] == target时需要移动的是 l 还是 r 
        if(a[mid] > target)
            r = mid;
        else
            l = mid;
    }
    // 还需要辨别是选择 l 还是选择 r
    return l;
}

int main(){
    cin >> N;
}