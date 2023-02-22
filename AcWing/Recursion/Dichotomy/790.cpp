/* 数的三次方根 */
#include <bits/stdc++.h>
using namespace std;

double target;
double cube(double num){
    return (num * num * num);
}
double search(){
    double l = -10000,r = 10000;
    double mid = l + (r - l) / 2.0;
    while(r-l >= 1e-7){ //由于本题是取得小数点后六位当r-l的精度小于小数点后八位时结束循环
        if(target <= cube(mid)){
            // 这里的边界问题怎么解决
            r = mid;
        }
        else{
            l = mid;
        }
        mid = l + (r - l) / 2.0;
    }
    return l;
}

int main(){
    cin >> target;
    cout << fixed << setprecision(6) << search();
}
