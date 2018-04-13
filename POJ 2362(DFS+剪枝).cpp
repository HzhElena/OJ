#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=25;
int M,sum;//sum表示棍子总长
int len[maxn];
int vis[maxn];
bool dfs(int cnt,int left,int begin)//当前匹配第cnt条边,且该边剩余left长度,且当前轮从begin开始选棍子
{
    if(cnt==4) return true;//构造成功
    else for(int i=begin;i<M;i++)
        if(!vis[i])
        {
            vis[i]=true;
            if(left==len[i])
            {
                if(dfs(cnt+1,sum/4,0)) return true;
            }
            else if(len[i]<left)
            {
                if(dfs(cnt,left-len[i],i+1)) return true;
            }
            vis[i]=false;
        }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int max_len=0;
        sum=0;
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            scanf("%d",&len[i]);
            max_len=max(max_len,len[i]);
            sum+=len[i];
        }
        if(sum%4!=0||max_len>sum/4)
        {
            printf("no\n");
            continue;
        }
        //sort(len,len+M); //可以不用排序
        memset(vis,0,sizeof(vis));
        if(dfs(1,sum/4,0)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
