#include <iostream>
#include <string>
using namespace std;
const int maxn = 1000;
int a[maxn],b[maxn],res[maxn*2];
int len_a,len_b,len_res;
void read(int num[],int &len)
{
    string s;
    cin>>s;
    len = 0;
    for(int i=s.size()-1;i>=0;--i)
        num[len++] = (s[i] - '0');
}
void multi()
{
    read(a,len_a);
    read(b,len_b);
    len_res = 0;
    int carry = 0;
    for(int pa=0;pa<len_a;++pa)
        for(int pb=0;pb<len_b;++pb)
    {
        res[pa + pb] += a[pa] * b[pb]; // 先逐位相乘 后计算进位
        len_res = pa+pb+1;
    }
    for(int i=0;i<len_res;++i)
    {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    if(carry != 0)
        res[len_res++] = carry;
    for(int i=len_res-1;i>=0;--i)
        cout<<res[i];
}
int main()
{
    multi();
    return 0;
}
