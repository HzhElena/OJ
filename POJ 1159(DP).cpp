#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 5000+5;
int dp[2][maxn];
int main()
{
    int N;
    cin>>N;
    string a,b;
    cin>>a;
    b = a;
    reverse(b.begin(),b.end());
    int e = 0;
    // 求 a 和 b 字符串的最长公共序列
    // 滚动数组
    for(int i=1;i<=N;++i){
        for(int j=0;j<N;++j)
    {
        if(a[i-1] == b[j]) dp[e][j] = max(dp[e][j],dp[1-e][j-1]+1);
        dp[e][j] = max(dp[e][j],dp[e][j-1]);
        dp[e][j] = max(dp[e][j],dp[1-e][j]);
    }
        e = 1-e;
    }
    cout<<N - dp[1-e][N-1]<<endl;
    return 0;
}
