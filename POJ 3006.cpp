#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000000+5;
bool isprime[maxn];

int main()
{
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<maxn;++i)
    {
        if(isprime[i]){
            for(int j=2;j*i<maxn;++j)
                isprime[i*j] = false;
        }
    }
    int a,d,n;
    while(scanf("%d %d %d",&a,&d,&n) && !(a==0 && d==0 && n==0))
    {
        int cnt = 0;
        while(true)
        {
            if(isprime[a] && ++cnt == n)
            {
                printf("%d\n",a); break;
            }
            a += d;
        }
    }
    return 0;
}
