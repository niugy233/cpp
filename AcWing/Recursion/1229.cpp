#include <bits/stdc++.h>
using namespace std;

int ans[4];
// 比较判断输出位置并输出
// 冒泡排序
void solve(){
    for(int i = 0;i<3;i++){
        for(int j = i;j<3;j++){
            if(ans[i] > ans[j]){
                int tmpe = ans[i];
                ans[i] = ans[j];
                ans[j] = tmpe;
            }
        }
    }
    for(int i = 0;i<3;i++){
        if(ans[i] / 10000 == 0 || ans[i] == ans[i+1]) continue;
        cout << ans[i] / 10000 << '-';
        if(ans[i] % 10000 / 100 < 10)
            cout << 0 << (ans[i] % 10000) / 100 << '-';
        else
            cout << (ans[i] % 10000) / 100 << '-';
        if(ans[i] % 100 < 10)
            cout << 0 << ans[i] % 100 << endl;
        else
            cout << ans[i] % 100 << endl;
    }
}
// 判断是否是闰年
bool judgeyear(int year){
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    return false;
}
// 判断合法性
bool judge(int year,int month,int day){
    if(year < 60)
        year = 20 * 100 + year;
    else
        year = 19 * 100 + year;
    if(month < 13 && month > 0){
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            if(day > 0 && day <= 31)
                return true;
            return false;
        }
        else if(month == 2){
            // 是闰年
            if(judgeyear(year)){
                if(day > 0 && day <= 29)
                    return true;
                return false;
            }
            else 
                if(day > 0 && day <= 28)
                    return true;
                return false;
        }
        else{
            if(day > 0 && day < 30)
                return true;
            return false;
        }
    }
    return false;
}

int print(int year,int month,int day){
    int res = 0;
    if(year < 60)
        year = 20 * 100 + year;
    else
        year = 19 * 100 + year;
    return res = year * 10000 + month * 100 + day;
}
int main(){
    int a,b,c;
    char e,f;
    cin >> a >> e >> b >> f >> c;
    if(judge(a,b,c))
        ans[0] = print(a,b,c);
    if(judge(c,a,b))
        ans[1] = print(c,a,b);
    if(judge(c,b,a))
        ans[2] = print(c,b,a);
    solve();
    return 0;
}