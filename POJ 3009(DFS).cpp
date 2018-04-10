#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 25;
int W,H,result,startx,starty,endx,endy;
int dirx[] = {-1,1,0,0};
int diry[] = {0,0,1,-1};
int maze[maxn][maxn];
bool inSquare(int x,int y)
{
    return (x<H && x>=0 && y<W && y>=0);
}
void dfs(int x,int y,int path)
{
    if(x == endx && y == endy) {
        if(result > path) result = path;
        return;
    }
    if(path == 10 || path >= result) return ;
    for(int i=0;i<4;++i)
    {
        int tmpx = dirx[i] + x, tmpy = diry[i] + y;
        while(inSquare(tmpx,tmpy) && maze[tmpx][tmpy] != 1)
        {
            if(tmpx == endx && tmpy == endy) {
                ++path;
                if(path < result) result = path;
                return;
            }
            tmpx += dirx[i];
            tmpy += diry[i];
        }
        if((tmpx == x + dirx[i] && tmpy == y+diry[i]) || !inSquare(tmpx,tmpy))
            continue;
        ++path;
        maze[tmpx][tmpy] = 0;
        dfs(tmpx-dirx[i],tmpy-diry[i],path);
        --path;
        maze[tmpx][tmpy] = 1;
    }
}
void solve()
{
    result = 11;
    for(int i=0;i<H;++i)
        for(int j=0;j<W;++j){
            if(maze[i][j] == 2) {startx = i; starty = j; maze[i][j] = 0;}
            if(maze[i][j] == 3) {endx = i; endy = j;}
    }
    dfs(startx,starty,0);
    if(result == 11)
        printf("%d\n",-1);
    else
        printf("%d\n",result);
}
int main()
{
    while(scanf("%d %d",&W,&H) != EOF && !(W==0 && H==0))
    {
        for(int i=0;i<H;++i)
            for(int j=0;j<W;++j)
                scanf("%d",&maze[i][j]);
        result = 11;
        solve();
    }
    return 0;
}
