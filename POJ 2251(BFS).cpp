#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 35;
int X,Y,Z;
char maze[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
struct node
{
    int z;
    int x;
    int y;
    int path;
    node(int zz=0,int xx=0,int yy=0,int p = 0):z(zz),x(xx),y(yy),path(p) {}
};
node st;

int dirx[] = {0,0,0,0,1,-1};
int diry[] = {1,-1,0,0,0,0};
int dirz[] = {0,0,1,-1,0,0};

int bfs()
{
    queue<node> q;
    q.push(st);
    vis[st.x][st.y][st.z] = true;
    node tmp,cur;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for(int i=0;i<6;++i)
        {
            int tmpx = tmp.x + dirx[i],tmpy = tmp.y + diry[i], tmpz = tmp.z + dirz[i];
            if(tmpx <0 || tmpx >= X || tmpy<0 || tmpy>=Y || tmpz<0 || tmpz>=Z)
                continue;
            if(vis[tmpx][tmpy][tmpz] || maze[tmpz][tmpx][tmpy] == '#') continue;
            if(maze[tmpz][tmpx][tmpy] == 'E') {return tmp.path+1;}
            cur.x = tmpx, cur.y = tmpy, cur.z = tmpz, cur.path = tmp.path+1;
            vis[tmpx][tmpy][tmpz] = true;
            q.push(cur);
        }
    }
    return -1;
}
int main()
{
  //  freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&Z,&X,&Y) && Z!=0){
        for(int i=0;i<Z;++i){
            for(int j=0;j<X;++j){
                scanf("%s",maze[i][j]);
                for(int k=0;k<Y;++k){
                    if(maze[i][j][k] == 'S') {st.x = j; st.y = k; st.z = i; st.path = 0;}
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int res = bfs();
        if(res == -1) cout<<"Trapped!"<<endl;
        else cout<<"Escaped in "<<res<<" minute(s)."<<endl;
    }
    return 0;
}
