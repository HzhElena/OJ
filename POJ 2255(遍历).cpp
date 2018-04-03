#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int root;
const int maxn = 30;
int le[maxn],ri[maxn];
char t[maxn];
string preorder,inorder;
int change_to_int(char a)
{
    if(a<='Z' && a>='A') return a-'A';
    else return a-'a';
}
void build_tree(int &root,int pre_sta,int pre_en,int in_sta,int in_en)
{
    if(pre_en < pre_sta || in_en < in_sta) return;
    root = change_to_int(preorder[pre_sta]);
    t[root] = preorder[pre_sta];
    char tmp = preorder[pre_sta];
    int i,cnt;
    for(i=in_sta;i<=in_en;++i)
    {
        if(inorder[i] == tmp) break;
    }
    cnt = i-in_sta;
    build_tree(le[root],pre_sta+1,pre_sta+cnt,in_sta,i-1);
    build_tree(ri[root],pre_sta+cnt+1,pre_en,i+1,in_en);
}
void post_traverse(int root)
{
    if(root == -1) return;
    post_traverse(le[root]);
    post_traverse(ri[root]);
    cout<<t[root];
}
int main()
{
    while(cin>>preorder>>inorder)
    {
        memset(le,-1,sizeof(le));
        memset(ri,-1,sizeof(ri));
        build_tree(root,0,preorder.size()-1,0,inorder.size()-1);
        post_traverse(root);
        cout<<endl;
    }
    return 0;
}
