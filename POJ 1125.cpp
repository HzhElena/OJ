#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 0xfffffff
const int maxn = 100+5;
int dis[maxn][maxn];

int main()
{
   // freopen("in.txt","r",stdin);
    int n,m,a,b;
    while(scanf("%d",&n) && n!=0) {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                if(j!=i) dis[i][j] = INF;
                else dis[i][j] = 0;
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&m);
            for(int k=0;k<m;++k)
            {
                scanf("%d %d",&a,&b);
                dis[i][a] = b;
            }
        }
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    {
                        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
                    }
        int mindis = INF,maxdis = 0,start = 1;
        for(int i=1;i<=n;++i)
        {
            maxdis = 0;
            for(int j=1;j<=n;++j)
                maxdis = max(maxdis,dis[i][j]);
            if(mindis > maxdis)
            {
                start = i;
                mindis = maxdis;
            }
        }
        if(mindis == INF) cout<<"disjoint"<<endl;
        else cout<<start<<" "<<mindis<<endl;
    }
    return 0;
}
