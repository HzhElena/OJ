#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

const int maxn = 600+5;
string dic[maxn];
int dp[maxn];

int main()
{
 //   freopen("in.txt","r",stdin);
    int W,L;
    cin>>W>>L;
    string s;
    cin>>s;
    for(int i=0;i<W;++i)
        cin>>dic[i];
    for(int i=1;i<=L;++i)
    {
        dp[i] = dp[i-1] + 1;
        // Consider every possible word
        for(int j=0;j<W;++j)
        {
            int tmp = i-1;
            int len = dic[j].size();
            int pos = len-1;
            while(tmp >=0 && pos >= 0)
            {
                if(s[tmp] == dic[j][pos]) --pos;
                --tmp;
            }
            if(pos < 0)
                dp[i] = min(dp[i],dp[tmp+1]+(i-tmp-len-1));
        }
    }
    cout<<dp[L]<<endl;
    return 0;
}
