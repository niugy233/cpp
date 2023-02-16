/* [NOIP2001 普及组] 求先序排列 | P1030 */

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
string pre,in,post;
struct node{
    char value;
    node * l;
    node * r;
    node(char value_ = ' ',node *l_ = NULL,node * r_ = NULL) {value = value_;l = l_;r = r_;}
};

// void ReversePost(){
//     char temp;int i = 1;
//     while(post[i] )
// }
void BuildTrue(int l,int r,node * &root,int &t){
    int flag = -1;
    for(int i = r;i>=l;i--){
        if(post[t] == in[i]){
            flag = i;
            break;
        }
    }
    // 退出
    if(flag == -1) return;
    root = new node(in[flag]);
    // 左右分开
    t--;
    if(flag < r)
        BuildTrue(flag+1,r,root->r,t);
    if(flag > l)
        BuildTrue(l,flag-1,root->l,t);
}
// 先序遍历
void PreView(node * root){
    if(root == NULL) return;
    cout << root->value;
    PreView(root->l);
    PreView(root->r);
}
int main(){
    cin >> in >> post;
    int length = in.length();
    node * root1;
    int t = length-1;
    BuildTrue(0,length-1,root1,t);
    PreView(root1);
}