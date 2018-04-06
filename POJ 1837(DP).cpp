#include <iostream>
using namespace std;
const int maxn = 25;
const int t = 7500;
int C,G;
int w[maxn],pos[maxn];
int dp[maxn][t*2+1];
int main()
{
    cin>>C>>G;
    for(int i=0;i<C;++i)
        cin>>pos[i];
    for(int i=0;i<G;++i)
        cin>>w[i];
    dp[0][t] = 1;
    for(int i=1;i<=G;++i)
        for(int j=2*t;j>=0;--j)
            for(int k=0;k<C;++k)
                dp[i][j] += dp[i-1][j+pos[k] * w[i-1]];
    cout<<dp[G][t]<<endl;
    return 0;
}
