#include <iostream>
#include <queue>
using namespace std;
const int maxn = 100+5;
int pre_x[maxn][maxn],prey[maxn][maxn];
bool vis[maxn][maxn];
int A,B,C;
struct node
{
    int a;
    int b;
    int path;
    node(int aa,int bb,int p):a(aa),b(bb),path(p) {}
};
void print_path(int x,int y)
{
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    while(true)
    {
        int tmpx = pre_x[x][y];
        int tmpy = prey[x][y];
        if(tmpx == -1 || tmpy == -1) break;
        v.push_back(tmpx);
        v.push_back(tmpy);
        x = tmpx,y = tmpy;
    }
    for(int i=v.size()-2;i>=2;i-=2)
    {
        int a = v[i],b = v[i+1], nexta = v[i-2], nextb = v[i-1];
        if(a+b > nexta + nextb) {
            if(a > nexta) cout<<"DROP(1)"<<endl;
            else cout<<"DROP(2)"<<endl;
        }
        else if(a+b < nexta + nextb){
            if(a < nexta) cout<<"FILL(1)"<<endl;
            else cout<<"FILL(2)"<<endl;
        }
        else
        {
            if(a > nexta) cout<<"POUR(1,2)"<<endl;
            else cout<<"POUR(2,1)"<<endl;
        }
    }
}
int bfs(int &x,int &y)
{
    node start(0,0,0);
    queue<node> q;
    q.push(start);
    vis[0][0] = true;
    while(!q.empty())
    {
        start = q.front();
        node tmp = start;
        q.pop();
        for(int i=0;i<6;++i)
        {
            tmp = start;
            tmp.path++;
            if(i == 0) {
                if(tmp.b == 0) continue;
                else tmp.b = 0;
            }
            else if(i == 1) {
                if(tmp.a == 0) continue;
                else tmp.a = 0;
            }
            else if(i == 2){
                if(tmp.a == 0 || tmp.b == B) continue;
                else {
                    if(B >= tmp.b + tmp.a) // 注意更新的先后顺序,先更新 tmp.a 则 tmp.b 错误
                         tmp.b = tmp.a+tmp.b ,tmp.a = 0;
                    else
                        tmp.a = tmp.a+tmp.b - B,tmp.b = B;
                }
            }
            else if(i == 3){
                if(tmp.b == 0 || tmp.a == A) continue;
                else {
                    if(A >= tmp.a + tmp.b)
                        tmp.a = tmp.a+tmp.b, tmp.b = 0;
                    else
                        tmp.b = tmp.a+tmp.b-A, tmp.a = A;
               //     cout<<"tmp.a: "<<tmp.a<<"tmp.b: "<<tmp.b<<endl;
                }
            }
            else if(i == 4)
            {
                if(tmp.a == A) continue;
                else tmp.a = A;
            }
            else if(i == 5)
            {
                if(tmp.b == B) continue;
                else tmp.b = B;
            }
            if(!vis[tmp.a][tmp.b]) {
                    prey[tmp.a][tmp.b] = start.b;
                    pre_x[tmp.a][tmp.b] = start.a;
                    if(tmp.a == C || tmp.b == C) {x = tmp.a; y = tmp.b;return tmp.path;}
                    q.push(tmp);
                    vis[tmp.a][tmp.b] = true;
            }
        }
    }
    return -1;
}
int main()
{
    cin>>A>>B>>C;
    for(int i=0;i<maxn;++i)
        for(int j=0;j<maxn;++j)
            pre_x[i][j] = prey[i][j] = -1;
    int x,y;
    int res = bfs(x,y);
    if(res == -1) cout<<"impossible"<<endl;
    else {
            cout<<res<<endl;
            print_path(x,y);
    }
    return 0;
}
