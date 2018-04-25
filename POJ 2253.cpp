#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0xffffffff
const int maxn = 200+5;
int x[maxn],y[maxn];
double dis[maxn][maxn];
double res[maxn];
bool vis[maxn];
int main()
{
    int n,now = 1;
    while(scanf("%d",&n) && n!=0)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;++i){
            scanf("%d %d",&x[i],&y[i]);
            res[i] = INF;
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                dis[i][j] = sqrt(double(y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]));
            }
        int cur = 0;
        res[cur] = 0;
        for(int i=1;i<n;++i)
        {
            double mindis = INF;
            vis[cur] = true;
            for(int j=0;j<n;++j)
            {
                if(!vis[j])
                    res[j] = min(max(res[cur],dis[cur][j]),res[j]);
            }
            for(int j=0;j<n;++j)
            {
                if(!vis[j] && mindis > res[j]) {cur = j;mindis = res[j];}
            }
        }
        printf("Scenario #%d\n",now);
        printf("Frog Distance = %.3f\n\n",res[1]);
        ++now;
    }
    return 0;
}
