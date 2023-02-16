/* 
    例题洛谷：T271071
    高精度算法学习
    储存方式：数组存储
    涉及加减乘除
    模拟竖式计算
    long long 范围在 正负2的63次方
 */
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


string str1,str2;
int num1[101];
int num2[101];
int AddResult[102];
int SubtractResult[102];
int MultiplyResult[102];
bool flag = false;
int ls,la,lm;

// 相加 进位
void addTwoNum(){
    memset(AddResult,0,sizeof(AddResult));
    la = max(str1.length(),str2.length()) + 1;
    for(int i = 0;i<la;i++){
        AddResult[i] = num1[i] + num2[i];
        AddResult[i+1] = AddResult[i] / 10;
        AddResult[i] = AddResult[i] % 10;
    }
    if(AddResult[la] == 0 && la > 0){
        la--;
    }
}

// 相减 借位
//num1 -num2
// false 需要加符号
bool comp(){
    if(str1.length() < str2.length()) //如果被减数长度小于减数
        return false;
    else if(str1.length() == str2.length()){
        int length = str2.length();
        for(int i = 0;i<length;i++){
            if(num1[i] < num2[i]){
                return false;
            }
            break;
        }
        return true; //两者相等
    }
    else{
        return true;
    }
}
void subtractTwoNum(){
    flag = comp();
    memset(SubtractResult,0,sizeof(SubtractResult));
    ls = max(str1.length(),str2.length());
    if(flag){ //这个说明被减数大于减数
        for(int i = 0;i<ls;i++){
            if(num1[i]  < num2[i]){ //借位
                num1[i+1]--;
                num1[i]+=10;
            }
            SubtractResult[i] = num1[i]-num2[i];
        }
    }
    else{ //后数减去前数
        for(int i = 0;i<ls;i++){
            if(num2[i] < num1[i]){
                num2[i+1]--;
                num2[i] += 10;
            }
            SubtractResult[i] = num2[i] - num1[i];
        }
    }
    while(SubtractResult[ls] == 0 && ls > 1) ls--;
}

void multiplyTwoNum(){
    memset(MultiplyResult,0,sizeof(MultiplyResult));
    lm = str1.length() + str2.length();
    for(int i = 0;i<str1.length();i++){
        for(int j = 0;j<str2.length();j++){
            MultiplyResult[i+j] +- num1[i] * num2[i];
            MultiplyResult[i+1+j] += MultiplyResult[i+j] / 10;
            MultiplyResult[i+j] %= 10;
        }
    }
    if(MultiplyResult[lm] == 0 && lm > 0) lm--;

}
int main(){
    //处理数的输入
    cin >> str1 >> str2;
    int length = str1.length();
    for(int i = 0;i<length;i++){
        num1[length - 1 - i] = str1[i]- '0';
    }
    length = str2.length();
    for(int i = 0;i<length;i++){
        //类型转换
        num2[length-1-i] = str2[i] - '0';
    }
}