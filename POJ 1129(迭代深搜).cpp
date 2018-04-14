#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 30;
bool vis[maxn];
int index[maxn];
bool connect[maxn][maxn];
char c[maxn];
int len,total;
void dfs(int k)
{
    if(vis[k]) return;
    bool tmp[maxn];
    for(int i=0;i<maxn;++i)
        tmp[i] = false;
    for(int i=0;i<len;++i)
    {
        if(!connect[k][i] || !vis[i]) continue;
        tmp[index[i]] = true;
    }
    for(int i=1;i<=len;++i)
        if(!tmp[i]) {index[k]=i; break;}
    if(index[k] > total) total = index[k];
    vis[k] = true;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&len) && len!=0)
    {
        memset(vis,0,sizeof(vis));
        memset(connect,0,sizeof(connect));
        memset(index,0,sizeof(index));
        for(int i=1;i<=len;++i){
            scanf("%s",c);
            total = 1; //total draw
            int a = c[0]-'A',b;
            for(int i=2;i<strlen(c);++i)
            {
                b = c[i]-'A';
                connect[a][b] = connect[b][a] = true;
            }
        }
        for(int i=0;i<len;++i)
            dfs(i);
        cout<<total;
        cout<<(total == 1 ? " channel needed.":" channels needed.")<<endl;
    }
    return 0;
}
