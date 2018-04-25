#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
const int maxn = 2010 ;
const int inf = 0x3f3f3f3f  ;
char str[maxn][10] ;
int map[maxn][maxn] ;
int vis[maxn] ;
int dis[maxn] ;
int n ;
int prime()
{
    for(int i = 2;i <= n;i++)
    dis[i] = inf ;
    dis[1] = 0 ;
    memset(vis , 0 ,sizeof(vis)) ;
    int ans = 0 ;
    while(1)
    {
        int mi = inf ;int pos ;
        for(int i = 1;i <= n;i++)
        if(!vis[i] && dis[i] < mi)
        mi = dis[pos = i] ;
        if(mi == inf)break;
        vis[pos] = 1;
        ans += mi ;
        for(int j = 1;j <= n ;j++)
        dis[j] = min(dis[j] , map[pos][j]) ;
    }
    return ans ;
}
int main()
{
    while(scanf("%d" , &n) && n)
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%s" , &str[i][1]) ;
            for(int j = 1;j <= i;j++)
            {
                int sum = 0 ;
                for(int k = 1;k <= 7 ;k++)
                if(str[i][k] != str[j][k])
                sum++ ;
                map[i][j] = map[j][i] = sum ;
            }
        }
        int ans = prime() ;
        printf("The highest possible quality is 1/%d.\n" , ans) ;
    }
    return 0 ;
}
