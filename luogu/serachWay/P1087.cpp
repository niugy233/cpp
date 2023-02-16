/* P1087 [NOIP2004 普及组] FBI 树 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1100
int N;
string S;

struct  node{
    string value;
    node * left, * right;
    node(string value_ = " ",node * left_ = NULL ,node * right_ = NULL){value = value_;left = left_;right = right_;}
};

void BuiltFBITree(node * &root,string Date){
    if(Date.length() == 0) return;
    int lenegth = Date.length(); 
    root = new node(Date);
    BuiltFBITree(root->left,Date.substr(0,lenegth/2));
    BuiltFBITree(root->right,Date.substr(lenegth/2,lenegth/2));
    return;
}

char Judge(node * Node){
    int size = Node->value.length();
    char tmp = Node->value[0];
    bool flag = true;
    for(int i = 1;i<size;i++){
        if(tmp != Node->value[i]){
            flag = false;
            break;
        }
    }
    // 与tmp一样
    if(flag){
        if(tmp == '0'){
            return 'B';
        }
        return 'I';
    }
    return 'F';
}
//后序遍历
void DFSpost(node * root){
    if(root == NULL) return ;
    DFSpost(root->left);
    DFSpost(root->right);
    cout << Judge(root);
    return;
}
int main(){
    cin >> N >> S;
    node * root;
    BuiltFBITree(root,S);
    DFSpost(root);
}