#include <iostream>
#include <cstdio>
#include <cmath>
const int maxn = 1000000;
char num[maxn];
int main()
{
    char a,b;
    int N;
    scanf("%d",&N);
    // read number
    getchar();
    for(int i=N-1;i>=0;--i)
    {
        a = getchar();
        getchar();
        b = getchar();
        getchar();
        num[i] = a+(b-'0');
    }
    for(int i=0;i<N;++i)
    {
        if(num[i] > '9') {
            num[i] -= 10;
            num[i+1] += 1;
        }
    }
    for(int i=N-1;i>=0;--i) putchar(num[i]);
    return 0;
}
