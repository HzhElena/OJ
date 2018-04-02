#include <iostream>
#include <climits>
#include <cstdio>
#include <queue>
using namespace std;
// 结果为 0 或者 binary (11111 11111 11111) = 1<<16 -1
const int maxn = (1<<16)-1;
bool vis[maxn + 10];
// 翻转
int change(int state,int row,int col)
{
    int k;
    //使用异或操作，若k对应位为1 则改变为0
    k = 1<<(row*4 + col);
    state ^= k;
    if(row>=1) {k = 1<<((row-1)*4+col); state ^= k;}
    if(row<3) {k = 1<<((row+1)*4+col); state ^=k;}
    if(col>=1) {k = 1<<(row*4+col-1); state ^= k;}
    if(col<3) {k = 1<<(row*4+col+1); state ^= k;}
    return state;
}
int bfs(int start)
{
    queue<int> q;
    q.push(start);
    int step = 0;
    while(!q.empty())
    {
        int t = q.size();
        for(int i=0;i<t;++i)
        {
            int k = q.front();
            q.pop();
            // 使用
            if(k == 0 || k == maxn || step > 16) return step;
            for(int i=0;i<4;++i)
                for(int j=0;j<4;++j)
            {
                int w = change(k,i,j);
                if(!vis[w]) q.push(w);
                vis[w] = true;
            }
        };
        ++step;
    }
    return 100;
}
int main()
{
    char c;
    int start = 0;
   // freopen("in.txt","r",stdin);
    for(int i=0;i<16;++i)
    {
        cin>>c;
        if(c == 'b')  start += (1<<i);
    }
    int ans = bfs(start);
    if(ans > 16) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}
