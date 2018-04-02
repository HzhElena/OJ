//超时 未过
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1<<16;
bool vis[maxn];
struct node{
    int x;
    int y;
    int pre;
};
node path[maxn];
int flip(int state,int pos)
{
    state ^= (1<<pos);
    int row = pos/4,col = pos%4;
    for(int i=0;i<4;++i)
    {
        int tmp = 4*i + col,tmp2 = row*4 + i;
        if(tmp != pos) state ^= (1<<tmp);
        if(tmp2 != pos) state ^= (1<<tmp2);
    }
    return state;
}
int bfs(int start)
{
    queue<int> q;
    int step = 0;
    q.push(start);
    while(!q.empty())
    {
        int t = q.size();
        for(int i=0;i<t;++i)
        {
            int tmp = q.front();
            if(tmp == 0) return step;
            vis[tmp] = true;
            q.pop();
            for(int j=0;j<16;++j)
            {
                int res = flip(tmp,j);
                if(!vis[res]){
                    q.push(res);
                    path[res].pre = tmp;
                    path[res].x = j/4+1;
                    path[res].y = j%4+1;
                }
            }
        }
        ++step;
    }
}
int main()
{
    char c;
    int start = 0,i;
    for(int i=0;i<16;++i)
    {
        cin>>c;
        if(c == '+') start += (1<<i);
    }
    int step = bfs(start);
    int tmp= 0,ans[20][2];
    cout<<step<<endl;
    for(int i=step-1;i>=0;--i)
    {
        cout<<path[tmp].x<<" "<<path[tmp].y<<endl;
        tmp = path[tmp].pre;
    }
    return 0;
}
