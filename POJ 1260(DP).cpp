#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000+5;
int dp[maxn],sum[maxn],c[maxn],num[maxn];
int main()
{
    int M,n;
    scanf("%d",&M);
    while(M--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;++i){
            scanf("%d %d",&num[i],&c[i]);
            sum[i] = num[i] + sum[i-1];
            dp[i] = (num[i] + 10)* c[i] + dp[i-1];
            for(int j=0;j<i;++j)
                dp[i]= min(dp[i],dp[j] + (sum[i] - sum[j] + 10) * c[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
