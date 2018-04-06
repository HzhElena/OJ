#include <iostream>

using namespace std;
const int maxn = 100;
int dp[maxn]; // dp[i] 代表以 i 结尾的最长子序列长度
int a[] = {2, 1, 5, 3 ,6 ,4, 8, 9, 7};
int LIS(int n)
{
    for(int i=0;i<n;++i) dp[i] = 1;
    for(int i=1;i<n;++i)
        for(int j=0;j<i;++j)
            if(a[j]<a[i]) dp[i] = max(dp[i],dp[j]+1);
    int maxn = -1;
    for(int i=0;i<n;++i)
        maxn = max(maxn,dp[i]);
    int tmp = n,target = maxn;
    while(target >= 1){
        for(int i=0;i<tmp;++i)
            if(dp[i] == target) { cout<<a[i]<<" "; tmp = i; target--;}
    }
    cout<<endl;
    return maxn;
}
int main()
{
    cout<<LIS(9);
    return 0;
}
