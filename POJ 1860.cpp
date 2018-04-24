#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 250;
struct edge
{
    int st;
    int en;
    double commission;
    double rate;
};
edge E[maxn];
int N,M,S,len = 0;
double V,value[maxn];
bool vis[maxn],flag;
void spfa(int cur)
{
// 由于可以重复返回原来路径,不需要排除vis情况
 //   vis[cur] = true;
    if(flag) return;
    for(int i=0;i<M;++i)
    {
        if(flag) return;
        if(E[i].st == cur) {
            double tmp = (value[E[i].st] - E[i].commission)*E[i].rate;
            if(value[E[i].en] < tmp)
            {
                value[E[i].en] = tmp;
           //     cout<<E[i].en<<"  "<<tmp<<endl;
                if(E[i].en == S && tmp > V) {flag = true; return;}
                else spfa(E[i].en);
            }
        }
    }
   // vis[cur] = false;
}
int main()
{
    int j=0,s,e,c,r;
    // 读取 double 用 %lf
    scanf("%d %d %d %lf",&N,&M,&S,&V);
    for(int i=0;i<M;++i)
        {
            scanf("%d %d %lf %lf",&E[j].st,&E[j].en,&E[j].rate,&E[j].commission);
            E[j+1].st = E[j].en;
            E[j+1].en = E[j].st;
            ++j;
            scanf("%lf %lf",&E[j].rate,&E[j].commission);
            ++j;
        }
    M *= 2;
    value[S] = V;
    spfa(S);
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
