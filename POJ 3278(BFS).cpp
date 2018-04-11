#include <iostream>
#include <queue>
using namespace std;
const int maxn = 100000;
bool vis[maxn];
int N,K;
struct node
{
    int value;
    int path;
    node(int v,int p):value(v),path(p) {}
    bool operator< (const node &other) const {return value<other.value;}
};
int bfs()
{
    int res = maxn;
    node start(N,0);
    queue<node> q;
    q.push(start);
    vis[start.value] = true;
    while(!q.empty())
    {
        start = q.front();
        q.pop();
        int dx = start.value+1,dy = start.value-1,dz = start.value*2,tmp = start.path+1;
        if(dx == K || dy==K || dz == K) return tmp;
        if(dx<=maxn && dx>=0 && !vis[dx]) {vis[dx] = true;q.push(node(dx,tmp));}
        if(dy<=maxn && dy>=0 && !vis[dy]) {vis[dy] = true;q.push(node(dy,tmp));}
        if(dz<=maxn && dz>=0 && !vis[dz]) {vis[dz] = true;q.push(node(dz,tmp));}
    }
}
int main()
{
    cin>>N>>K;
    // 注意 N 或者 K 为0的时候 不要单独处理，因为 +1 之后就可以*2 以获得更大值
    if(N>=K) cout<<(N-K)<<endl;
    else cout<<bfs()<<endl;
    return 0;
}
