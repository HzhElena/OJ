#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0xfffffff
const int maxn = 100+5;
int M,N,head[maxn];
struct node
{
    int dist;
    int level;
    int prize;
};
struct e{
    int en;
    int weight;
    int next;
};
node v[maxn];
e edge[maxn*maxn];
int len = 1,min_level,max_level;
bool vis[maxn];
void dijkstra()
{
    v[1].dist = 0;
    for(int i=1;i<=N;++i)
    {
        int mindist = INF,cur;
        for(int j=1;j<=N;++j)
        {
            if(!vis[j] && v[j].dist < mindist) {mindist = v[j].dist; cur = j;}
        }
        vis[cur] = true;
        for(int j=head[cur];j!=0;j=edge[j].next)
        {
            int tmp = edge[j].en;
            if(!vis[tmp] && v[tmp].dist > v[cur].dist + edge[j].weight && v[tmp].level <= max_level && v[tmp].level>=min_level)
            {
                   v[tmp].dist = v[cur].dist + edge[j].weight;
            }
        }
    }
}
int main()
{
    int p,l,x;
    scanf("%d %d",&M,&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%d %d %d",&v[i].prize,&v[i].level,&x);
        v[i].dist = INF;
        for(int j=0;j<x;++j)
        {
            scanf("%d %d",&p,&l);
            edge[len].en = p;
            edge[len].next = head[i];
            edge[len].weight = l;
            head[i] = len;
            ++len;
        }
    }
     int mindist = INF;
    for(int i=1;i<=N;++i)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<maxn;++i) v[i].dist = INF;
        min_level = min(v[i].level,v[1].level);
        max_level = min_level + M;
        for(int i=1;i<=N;++i)
            if(v[i].level < min_level || v[i].level > max_level) vis[i] = true;
        dijkstra();
        for(int i=1;i<=N;++i)
       {
           mindist = min(mindist, v[i].dist + v[i].prize);
       }
    }
    cout<<mindist<<endl;
    return 0;
}
