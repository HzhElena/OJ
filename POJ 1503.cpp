#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 100+5;
int a[maxn]; // 0
int sum[maxn*2];
bool read(int num[],int &len)
{
    string s;
    cin>>s;
    len = 0;
    for(int i=s.size()-1;i>=0;--i)
    {
        num[len++] = s[i] -'0';
    }
    return (s!="0");
}
void add(int num[],int &len_num,int sum[],int &len_sum)
{
    int carry = 0,i=0;
    while(i<len_num || i<len_sum)
    {
        int tmp = carry + num[i] + sum[i];
        sum[i] = tmp % 10;
        carry = tmp / 10;
        ++i;
    }
    if(carry!=0) sum[i++] = carry;
    len_sum = i;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int len_sum = 1,len_a = 0;
    while(read(a,len_a))
    {
        add(a,len_a,sum,len_sum);
    }
    for(int i=len_sum-1;i>=0;--i)
        cout<<sum[i];
    return 0;
}
