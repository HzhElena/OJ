#include <iostream>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 500+5;
int dist[maxn][maxn];
int c[maxn],ans;
bool vis[maxn];
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        ans = 0;
        for(int i=0;i<N;++i){
            vis[i] = false;
            c[i] = INF;
            for(int j=0;j<N;++j)
                scanf("%d",&dist[i][j]);
        }
        c[0] = 0;
        int start;
        for(int j=0;j<N;++j)
        {
            int mindist = INF;
            for(int i=0;i<N;++i)
                if(!vis[i] && mindist > c[i])
                {
                    start = i;
                    mindist = c[i];
                }
            ans = max(ans,mindist);
            vis[start] = true;
            for(int i=0;i<N;++i)
            {
                c[i] = min(c[i],dist[start][i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
