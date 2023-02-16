/* 有旋转的treap树模板 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int lc[MAXN], rc[MAXN], val[MAXN], ord[MAXN], siz[MAXN], w[MAXN];
int sz = 0, rt = 0;

inline int Rand(){
	static unsigned long long r = 2333;     //static不能少，r的初值可以自己定
	return (r *= 233333) %= 2147483647;     //每次r乘上的数也可以自己定
}

inline void pushup(int x) { siz[x] = siz[lc[x]] + siz[rc[x]] + w[x]; }

void lrotate(int &root){
    int tmp = rc[root];
    rc[root] = lc[tmp], lc[tmp] = root;
    siz[tmp] = siz[root];
    pushup(root);
    root = tmp;
}

void rrotate(int &root){
    int tmp = lc[root];
    lc[root] = rc[tmp], rc[tmp] = root;
    siz[tmp] = siz[root];
    pushup(root);
    root = tmp;
}

void insert(int &root, int x){
    if(!root){
        sz++, root = sz;
        siz[root] = w[root] = 1;
        val[root] = x, ord[root] = Rand();
        return;
    }
    siz[root]++;
    if(val[root] == x) w[root]++;
    else if(val[root] < x){
        insert(rc[root], x);
        if(ord[rc[root]] < ord[root]) lrotate(root);
    }
    else{
        insert(lc[root], x);
        if(ord[lc[root]] < ord[root]) rrotate(root);
    }
}

bool del(int &root, int x){
    if(!root) return false;
    if(val[root] == x){
        if(w[root] > 1){ w[root]--, siz[root]--; return true; }
        if(!lc[root] || !rc[root]){
            root = lc[root] + rc[root];
            return true;
        }
        else if(ord[lc[root]] < ord[rc[root]]){
            rrotate(root);
            return del(root, x);
        }
        else{
            lrotate(root);
            return del(root, x);
        }
    }
    else if(val[root] < x){
        bool flag = del(rc[root], x);
        if(flag) siz[root]--;
        return flag;
    }
    else{
        bool flag = del(lc[root], x);
        if(flag) siz[root]--;
        return flag;
    }
}

int queryrnk(int root, int x){
    if(!root) return 0;
    if(val[root] == x) return siz[lc[root]] + 1;
    else if(x > siz[lc[root]] + w[root]) return siz[lc[root]] + w[root] + queryrnk(rc[root], x);
    else return queryrnk(lc[root], x);
}

int querynum(int root, int x){
    if(!root) return 0;
    if(x <= siz[lc[root]]) return querynum(lc[root], x);
    else if(x > siz[lc[root]] + w[root]) return querynum(rc[root], x - siz[lc[root]] - w[root]);
    else return val[root];
}

int ans = 0;
void querypre(int root, int x){
    if(!root) return;
    if(val[root] < x) ans = root, querypre(rc[root], x);
    else querypre(lc[root], x);
}
void querysub(int root, int x){
    if(!root) return;
    if(val[root] > x) ans = root, querysub(lc[root], x);
    else querysub(rc[root], x);
}

signed main(){
    int op = 0, n = 0; cin >> op >> n;
    switch(op){
        case 1: insert(rt, n); break;
        case 2: del(rt, n); break;
        case 3: cout << queryrnk(rt, n) << endl;
        case 4: cout << querynum(rt, n) << endl;
        case 5: querypre(rt, n); cout << ans << endl; break;
        case 6: querysub(rt, n); cout << ans << endl; break;
    }
    return 0;
}
