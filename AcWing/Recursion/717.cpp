/* 简单斐波那切数列 */

#include <bits/stdc++.h>
using namespace std;

int N;
void DFS(int Date1,int Date2,int deep){
    if(deep > N - 2) return;
    cout << Date1+Date2 << ' ';
    DFS(Date2,Date1+Date2,1+deep);
    return;
}
int main(){
    cin>>N;
    if( N == 1)
        cout << 0;
    else 
        cout << 0 << ' ' << 1 << ' ';
    DFS(0,1,1);
}