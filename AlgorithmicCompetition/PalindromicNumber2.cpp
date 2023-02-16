#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 6005
int dp[MAXN][3];

struct node{
    int id;
    int cost;
};
vector<node> tree[MAXN];
int N;

void dfs1(int father){
    int one = 0, two = 0;
    for(int i = 0;i<tree[father].size();i++){

        node child = tree[father][i];
        dfs1(child.id);
        int cost = child.cost + dp[child.id][0];
        if(cost >= one){
            two = one;
            one = cost;
        }
        if(cost < one && cost > two){
            two = cost;
        }
    }
    dp[father][0] = one;
    dp[father][1] = two;
}

void dfs2(int father){
    for(int i = 0;i<tree[father].size();i++){
        node child = tree[father][i];
        if(dp[child.id][0] + child.cost == dp[father][0]){
            dp[child.id][2] = max(dp[child.id][1],dp[father][2]) + child.cost;
        }
        else{
            dp[child.id][2] = max(dp[child.id][0] ,dp[father][2]) + child.cost;
        }
        dfs2(child.id);
    }
}
int main(){
    cin >> N;
    int x,y;
    for(int i = 1;i<=N;i++){
        tree[i].clear();
    }
    memset(dp,0,sizeof(dp));
    for(int i = 2;i<=N;i++){
        cin >> x >> y;
        node temp;
        temp.cost = y;
        temp.id = x;
        tree[i].push_back(temp); // x是i的子结点
    }
}