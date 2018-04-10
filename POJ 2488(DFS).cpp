#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 30;
// sort lexicographically
int dir[][2] = {
    -1,-2,1,-2,
    -2,-1,2,-1,
    -2,1,2,1,
    -1,2,1,2
};
int resx[maxn],resy[maxn];
bool vis[maxn][maxn];
int p,q;
bool dfs(int x,int y,int k)
{
    if(k == 0) return true;
    for(int i=0;i<8;++i)
    {
        int tmpx = x + dir[i][0], tmpy = y + dir[i][1];
        if(tmpx<1 || tmpx>p || tmpy<1 || tmpy>q || vis[tmpx][tmpy]) continue;
        vis[tmpx][tmpy] = true;
        resx[k] = tmpx,resy[k] = tmpy;
        if(dfs(tmpx,tmpy,k-1)) return true;
        vis[tmpx][tmpy] = false;
    }
    return false;
}
bool total_dfs(int &x,int &y)
{
    int k = p * q;
    for(int j=1;j<=q;++j){
        for(int i=1;i<=p;++i)
        {
            resx[k] = i,resy[k] = j;
            vis[i][j] = true;
            if(dfs(i,j,k-1)) {x=i,y=j; return true;}
            vis[i][j] = false;
        }
    }
    return false;
}
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;++i)
    {
        cout<<"Scenario #"<<i<<":"<<endl;
        cin>>p>>q;
        memset(vis,0,sizeof(vis));
        int x,y;
        if(total_dfs(x,y)) {
            for(int i=p*q;i>=1;--i)
            {
                cout<<(char)('A'+(resy[i]-1))<<resx[i];
            }
            cout<<endl<<endl;
        }
        else {
            cout<<"impossible";
            cout<<endl<<endl;
        }
    }
    return 0;
}
