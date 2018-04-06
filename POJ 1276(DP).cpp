// 多重背包模板
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100000+5;
const int t = 11;
int dp[maxn];
int n[t],D[t];
void ZeroOnePack(int M,int cost,int weight)
{
    for(int i=M;i>=cost;--i)
        dp[i] = max(dp[i],dp[i-cost] + weight);
}
void CompletePack(int M,int cost,int weight)
{
    for(int i=cost;i<=M;++i)
        dp[i] = max(dp[i],dp[i-cost] + weight);
}
void MultiPack(int M,int cost,int weight,int num)
{
    if(cost * num >= M)
    {
        CompletePack(M,cost,weight);
        return;
    }
    int k=1;
    while(k < num)
    {
        ZeroOnePack(M,k*cost,k*weight);
        num -= k;
        k = k*2;
    }
    ZeroOnePack(M,num*cost,num*weight);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int N,cash;
    while(cin>>cash>>N){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;++i)
        {
            cin>>n[i]>>D[i];
        }
        if(cash == 0 || N == 0) {cout<<0<<endl; continue;}
        for(int i=0;i<N;++i)
            MultiPack(cash,D[i],D[i],n[i]);
        cout<<dp[cash]<<endl;
    }
    return 0;
}
