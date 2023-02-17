    #include <bits/stdc++.h>
    using namespace std;

    #define INF 10000
    int ans = INF;
    char a[10][10];
    char b[10][10];

    // 函数改变A点相邻点的状态
    void turn(int i,int j){
        a[i][j] ^= 1; //自己
        a[i+1][j] ^= 1; // 下边
        a[i-1][j] ^= 1; //上边
        a[i][j+1] ^= 1; //右边
        a[i][j-1] ^= 1; //左边
    }


    void DFS(int deep,int step){
        if(deep == 6){ //第一行的5个开关做了组合
            // 保持此时的状态
            memcpy(b,a,sizeof(a));
            for(int i = 1;i<=4;i++){
                for(int j = 1;j<=5;j++){
                        if(a[i][j] == '0'){
                        turn(i+1,j);
                        step++;
                    }
                }
            }
            bool done = true;
            for(int i = 1;i<=5;i++){
                if(a[5][i] == '0') done = false; 
            }
            if(done) ans = min(ans,step);
            
            memcpy(a,b,sizeof(a));
            return;
        }
        // deep行选择不改变
        DFS(deep+1,step);
        // deep行选择改变
        turn(1,deep);
        DFS(deep+1,step+1);
        // 恢复原样  
        turn(1,deep);
    }


    int main(){
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            for(int i = 1;i <= 5;i++)
                for(int j = 1;j <= 5;j++)
                    cin >> a[i][j]; 
            DFS(1,0);
            if(ans > 6)
            ans = -1;
            cout << ans << endl;
            ans = INF;
        }
    }