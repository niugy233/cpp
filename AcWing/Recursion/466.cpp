// #include <bits/stdc++.h>
// using namespace std;

// int Date[2];
// int year[2],month[2],day[2];
// // 判断是否是闰年闰年
// bool judgeYear(int year){
//     if((year % 100 == 0 && year % 4 == 0) || year % 400 == 0 )
//         return true;
//     return false;
// }
// // 分离年月日
// void division(){
//     for(int i = 0;i<2;i++){
//         year[i] = Date[i] / 1000;
//         month[i] = (Date[i] / 100) % 100;
//         day[i] = Date[i] % 10;
//     }
//     return;
// }
// // 判断月份有多少天
// int judgeMonth(int monNum,int yearNum){
//     if(monNum == 2){
//         if(judgeYear(yearNum))  return 29;
//         else return 28l
//     }
//     if(monNum == 1 || monNum == 3 || monNum == 7 || monNum == 8 || monNum == 10 || monNum == 12){
//         return 31;
//     }
// }
// // 判断回文数
// bool judgePnum(int yearNum,int monNum,int dayNum){
//     int left[4],right[4];
//     for(int i = 3;i>=0;i++){
//         left[i] = yearNum / pow(10,i); 
//     }
//     right[0] = monNum / 10;
//     right[1] = monNum % 10;
//     right[2] = dayNum / 10;
//     right[3] = dayNum % 10;
//     int l = 0,r = 7;
//     for(int i = 0;i<4;i++){
//         if(right[i] != left[i])
//             return false;   
//     }
//     return true;
// }
// // 解决问题
// int solve(){
//     // 怎么设计循环主体
//     // 循环年
//     int key = year[1] - year[0];
//     if(key == 0){ // 说明两者是同一年
//     }
//     else{ //说明两者不是同一年

//     }
// }
// int main(){
//     for(int i = 0;i<2;i++){
//         cin >> Date[i];
//     }
//     division();
// }


// 回文数的枚举都可以用这样的方式枚举
/*  1枚举前四位推导后四位
    2判断范围是否合法
    3判断日期是否合法 */

#include <bits/stdc++.h>
using namespace std;

int cnt;

int judgeYear(int year){
    if((year % 100 != 0 && year % 4 == 0) || year % 400 == 0 )
        return 29;
    return 28;
}

bool check(int Date){
    // 获取年月日
    int year = Date / 10000;
    int month = (Date / 100) % 100;
    int day = Date % 100;
    // 日期合理
    if(month > 0  && month <13 && day > 0){
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            if(day <= 31)
                return true;
        }
        else if(month == 2){
            if(day <= judgeYear(year))
                return true;
        }
        else 
            if(day <= 30)
                return true;
    }
    return false;
}


int main(){
    int Date1,Date2;
    cin >> Date1 >> Date2;
    // 枚举前四位数推到后四位数
    for(int i = 0;i<10000;i++){
        int r = i,l = i;
        for(int j = 1;j<=4;j++){
            r = r * 10 + l % 10; l /= 10;
        }
        // 符合该条件的
        if(r <= Date2 && r >= Date1 && check(r)) cnt++;   
    }
    cout << cnt << endl;
}

