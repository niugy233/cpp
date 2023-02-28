#include <bits/stdc++.h>
using namespace std;

// 矩阵n*m
int n,m,q;
int a,b,c,d;

int matrix[1005][1005];
// 储存从1，1到i，j的矩阵和
int summatrix[1005][1005];

void CalcSumMatrix(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            summatrix[i][j] = summatrix[i][j-1] + matrix[i][j] + summatrix[i-1][j] - summatrix[i-1][j-1];
        }
    }
}
int calcres(){
    return (summatrix[c][d] - (summatrix[a - 1][d] + summatrix[c][b - 1]) + summatrix[a-1][b-1]); 
}

int main(){
    cin >> n >> m >>  q;
    memset(summatrix,0,sizeof(summatrix));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j <= m;j++){
            cin >> matrix[i][j];
        }
    }
    CalcSumMatrix();
    while(q--){
        cin >> a >> b >> c >> d;    
        cout << calcres() << endl; 
    }
}