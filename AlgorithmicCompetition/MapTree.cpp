/* 可以看到储存数据量大容易溢出后面提供一种更加合理的存储方式 */
//使用链表存储数据

/* #include <bits/stdc++.h>
using namespace std;

struct Trie{
    Trie * next[26];
    int num;
    Trie(){
        for(int i = 0;i<26;i++){
            next[i] = NULL;
        }
        num = 0;
    }
};
Trie Root;

// 创建字典树
void Insert(char str[]){
  Trie * p = & Root;
  int len = strlen(str);
  for(int i = 0;i<len;i++){
    if(p->next[str[i] - 'a'] == NULL){
        p->next[str[i] - 'a'] = new Trie;
    }
    p = p->next[str[i] - 'a'];
    p->num++;
  }  
}

int FindNum(char str[]){
    Trie * p = &Root;
    for(int i = 0;str[i];i++){
        if(p->next[str[i] - 'a'] == NULL) 
            return 0;
        p = p->next[str[i] - 'a'];
    }  
    return p->num;
}
int main(){
    char str[20];
    int len = 0;
    while(gets(str)){
        Insert(str); 
    }
    while(gets(str)){}
    cout << Find(str);
} */

/* 使用数组存储数据 */

#include <bits/stdc++.h>
using namespace std;

int Trie[1000][26];
int num[1000];
int pos = 1;
void Insert(char str[]){
    int k = 0;
    for(int i = 0;str[i];i++){
        if(Trie[k][str[i] - 'a'] == 0){ // 从未出现过
            Trie[k][str[i] - 'a'] = pos++;
        }
        k = Trie[k][str[i] - 'a'];
        num[k]++;
    }
}


int Findd(char str[]){
    int k = 0;
    for(int i = 0;str[i];i++){
        int n = str[i] - 'a';
        if(Trie[k][n] == 0){
            return 0;
        }
        k = Trie[k][n];
    }
    return num[k];
}
int main(){
    char str[20];
    int len = 0;
    memset(Trie,0,sizeof(Trie));
    memset(num,0,sizeof(num));
    while(gets(str)){
        Insert(str);
    }
    while(gets(str)){}
}