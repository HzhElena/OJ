#include<stdio.h>
#include<math.h>
#define eps 0.0000000001
void init(), work();
double n, m, k;

void init()
{
    while(scanf("%lf %lf", &n, &m) != EOF)
        work();
}
void work()
{
    long long left, right, mid;
    left = 0;
    right = 1000000002;
    while(left + eps < right){
        mid = (left + right) / 2;
        if(pow(mid, n) - m > 0)
            right = mid;
        else
            if(pow(mid, n) - m < 0)
                left = mid;
            else{
                printf("%.0ld\n", mid) ;
                return;
            }
    }
}
int main()
{
    init();
    return 0;
}
