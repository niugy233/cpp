/* 有旋转的treap树 */

#include <iostream>
using namespace std;

// ctrl + f;
// 数组形式

const int MAXN = 1e5 + 10;
int lc[MAXN];		//节点MAXN的左孩子
int rc[MAXN];		//节点MAXN的右孩子
int val[MAXN];		//节点MAXN的键值(即为节点的key值)
int ord[MAXN];		//节点MAXN的priority值
int siz[MAXN];		//以节点MAXN为根节点的子树大小
int w[MAXN];		//与节点MAXN键值相同的节点数目

// c++的特性变量的引用类似于c中的指针但不同，相当于一个别名，用一块内存root改变其他也改变
void lrotate(int & root){

}
//这里root是val[x]中的x是新插入的结点的根节点
// 只需要完成右旋操作就行，判断是否需要右旋放在insert函数中
void rrotate(int & root){
    int temp = rc[root];
    rc[root] = lc[temp],lc[temp] = root;

}

int main(){
    
}