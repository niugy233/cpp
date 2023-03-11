// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1000010;
// int N;
// int A[MAXN],B[MAXN],C[MAXN];
// long long  cnt = 0;


// int Binary_search_C(int a[],int target){
//     int l = -1,r = N;
//     int mid;
//     while(l+1 < r){
//         mid = (l+r) >> 1;
//         if(a[mid] > target)
//             r = mid;
//         else
//             l = mid;
//     }
//     return l+1;
// }


// int Binary_search_A(int a[],int target){
//     int l = -1,r = N;
//     int mid;
//     while(l+1 < r){
//         mid = (l+r) >> 1;
//         if(a[mid] >= target)
//             r = mid;
//         else
//             l = mid;
//     }
//     return l+1;
// }

// int main(){
//     cin >> N;
//     for(int i = 0;i<N;i++)
//         cin >> A[i];
//     for(int i = 0;i<N;i++)
//         cin >> B[i];
//     for(int i = 0;i<N;i++)
//         cin >> C[i];
//     sort(A,A+N);
//     sort(B,B+N);
//     sort(C,C+N);

//     /* 枚举数组B */
//     for(int i = 0;i<N;i++){
//         // 求出数组A小于B[i]的数量
//         int j = Binary_search_A(A,B[i]);
//         // 求出数组C大于B[i]的数量
//         int k = Binary_search_C(C,B[i]);
//         // 可能j与k想乘的结果是超出int的存储范围的
//         cnt += (long long)(j*(N-k));
//     }
//     cout << cnt << endl;
//     return 0;
// }

// /* 该程序无法运行文档名称不符合规范 */

// /* 使用前缀和的方式求解递增三元组 */
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 30;
// int N;
// int num[3][MAXN];
// int cntA[MAXN],cntC[MAXN];
// int prefixSUmA[MAXN],prefixSUmC[MAXN];

// long long cnt = 0;

// int main(){
//     cin >> N;
//     for(int i = 0;i<3;i++){
//         for(int j = 1;j<=N;j++){
//             cin >> num[i][j];
//             num[i][j]++; //保证数组中最小的数是1
//         }
//     }
// // 计算num[i][j]在A C 数组中的数量
//     for(int i = 1;i<=N;i++){
//         cntA[num[0][i]]++;
//         cntC[num[2][i]]++;
//     }
// // 计算前缀和
//     for(int i = 1;i<MAXN;i++){
//         // <=i           == i          <i
//         prefixSUmA[i] = cntA[i] + prefixSUmA[i-1];
//         prefixSUmC[i] = cntC[i] + prefixSUmC[i-1];
//     }

//     // 枚举数列B
//     for(int i = 1;i<=N;i++){
//         long long j = prefixSUmA[num[1][i] - 1];
//         long long k = prefixSUmC[num[1][i]];
//         if(j >= 1 && k <= N){
//             cnt += j*(N-k);
//         }
//     }
//     cout << cnt << endl;
// }

    /* 用双指针的方式求解 */
    #include <bits/stdc++.h>
    using namespace std;

    const int MAXN = 1e5+10;
    int num[3][MAXN];
    int N;
    long long cnt = 0;

    int main(){
        cin >> N;
        for(int i = 0;i<3;i++){
            for(int j = 1;j<=N;j++){
                cin >> num[i][j];
            }
            // 从1到0
            sort(num[i]+1,num[i]+N+1);
        }
        // 双指针法

        // 枚举数组B
        // 双指针法仅用便利一次即可
        int j = 1,k = 1;
        for(int i = 1;i<=N;i++){
            // 由于三个数组均为有序数组可以用双指针的方式求解
            while(j <= N && num[0][j] < num[1][i]) j++;
            while(k <= N && num[2][k] <= num[1][i]) k++;
            cnt +=  (long long) (j-1) * (N-k+1);
        }
        cout << cnt << endl;
    }
