#include <iostream>
#include <map>
#include <string>
using namespace std;
const int maxn = 30+5;
struct e
{
    int st;
    int en;
    double weight;
};
double init[maxn],cur[maxn];
e edge[maxn*maxn];
int n,t,len = 0;
int main()
{
    string s1,s2;
    double c;
    bool flag;
    int num = 1;
    while(cin>>n && n!=0)
    {
        flag = false;
        len = 0;
        for(int i=0;i<n;++i){
            cur[i] = -1;
            init[i] = -1;
        }
        map<string,int> m;
        for(int i=0;i<n;++i)
        {
            cin>>s1;
            m[s1] = i;
        }
        cin>>t;
        for(int i=0;i<t;++i)
        {
            cin>>s1>>c>>s2;
            edge[len].st = m[s1];
            edge[len].en = m[s2];
            edge[len].weight = c;
            ++len;
        }
        cur[0] = 1;
        for(int i=0;i<n;++i){
            for(int j=0;j<len;++j)
                if(cur[edge[j].st] * edge[j].weight > cur[edge[j].en])
                    cur[edge[j].en] = cur[edge[j].st] * edge[j].weight;
        }
        for(int j=0;j<len;++j)
            if(cur[edge[j].st] * edge[j].weight > cur[edge[j].en])
        {
            flag = true;
            break;
        }
        cout<<"Case "<<num<<": ";
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        ++num;
    }
    return 0;
}
