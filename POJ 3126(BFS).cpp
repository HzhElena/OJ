#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 10000;
int prime[maxn],len;
bool isprime[maxn];
bool vis[maxn];
int num[][2] = {0,1,0,10,0,100,0,1000};
int st,en,res;
int bfs()
{
    queue<int> q;
    queue<int> q_num;
    q.push(st);
    q_num.push(0);
    vis[st] = true;
    while(!q.empty())
    {
        int tmp = q.front(),cur,tmp2 = tmp,cur2;
        int path = q_num.front();
        q.pop();
        q_num.pop();
        int i=0,k=10;
        while(tmp2) {
            num[i++][0] = tmp2 % 10;
            tmp2 /= 10;
        }
        for(int i=0;i<4;++i)
        {
            cur = tmp-num[i][0] * num[i][1];
            for(int j=0;j<10;++j)
            {
                if(i == 3 && j == 0) continue;
                cur2 = cur + num[i][1] * j;
                if(!isprime[cur2] || vis[cur2]) continue;
                if(cur2 == en) return path+1;
                vis[cur2] = true;
                q.push(cur2);
                q_num.push(path+1);
            }
        }
    }
    return -1;
}
int main()
{
    int N;
    bool flag = true;
    cin>>N;
    for(int j=2;j<maxn;++j){
        flag = true;
        for(int i=0;i<len;++i)
        {
            if(j % prime[i] == 0) flag = false;
        }
        if(flag) {prime[len++] = j; isprime[j] = true;}
    }
    while(N--)
    {
        cin>>st>>en;
        memset(vis,0,sizeof(vis));
        res = -1;
        if(st == en) cout<<0<<endl;
        else if(!isprime[st] || !isprime[en]) cout<<"Impossible"<<endl;
        else {
            res = bfs();
            if(res == -1) cout<<"Impossible"<<endl;
            else cout<<res<<endl;
        }
    }
    return 0;
}
