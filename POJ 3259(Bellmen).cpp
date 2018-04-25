#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
#define N 5210
#define INF 0xfffffff

int cnt, dist[N];
int n, m, w;

struct Edge
{
    int u, v, w, next;
}e[N];

void Add(int u, int v, int w)
{
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    cnt++;
}

bool bellmen_ford()///spfa模板；
{
    dist[1] = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<cnt;++j)
        {
            if(dist[e[j].v] > dist[e[j].u] + e[j].w)
            {
                dist[e[j].v] = dist[e[j].u] + e[j].w;
            }
        }
    }
    for(int j=0;j<cnt;++j)
        {
            if(dist[e[j].v] > dist[e[j].u] + e[j].w)
            {
                return true;
            }
        }
    return false;
}

int main()
{
    int T, a, b, c;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &w);
        cnt = 0;
        for(int i=1; i<=n; i++)
            dist[i] = INF;

        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            Add(a, b, c);
            Add(b, a, c);
        }
        for(int i=1; i<=w; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            Add(a, b, -c);
        }
        if( bellmen_ford() )///存在负环；
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
