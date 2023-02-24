

#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;

struct Sum{
    int s, c, d;
    bool operator<(const Sum &t)const
    {
        if(s != t.s) return s < t.s;
        if(c != t.c) return c < t.c;
        return d < t.d;
    }
};

// 这里是否有点浪费空间
Sum record[2 * N];

int main(){
    int num;
    cin >> num;
    // record从0开始
    int k = 0;
    for(int c = 0;c*c <=num;c++){
        for(int d = c;c*c+d*d <= num;d++){
            record[k++] = {c*c + d*d,c,d};
        }
    }
    // 字典序排列
    sort(record,record+k);
    // 枚举a，b
    // 这里想一下会不会超时
    for(int a = 0;a * a <= num;a++){
        for(int b = a; a *a + b*b <= num;b++){
            // 需要寻找的目标sum
            int target =num - a*a - b*b;
            // 二分是分数组的位置
            int l = 0,r = k-1;
            while(l + 1 < r){
                int mid = (l+r) >> 1;
                if(target <= record[mid].s)
                    r = mid;
                else 
                    l = mid;
            }
            // 最终l和r重合
            // 寻找到合适的a,b,c,d;
            if(record[l].s == target){
                printf("%d %d %d %d",a,b,record[l].c,record[l].d);
                return 0;
            }
        }
    }
    return 0;   
}