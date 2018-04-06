#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000+5;
double height[maxn];
double lest[maxn],rist[maxn];
int l[maxn],r[maxn];
int main()
{
    int N,top = 0;
    scanf("%d",&N);
    for(int i=1;i<=N;++i) {
        scanf("%lf",&height[i]);
        // has to be ++top; otherwise the previous top value is changed
        if(height[i] > lest[top]) {lest[++top] = height[i];}
        else
        {
            int low = 1,high = top;
            while(low<=high)
            {
                int mid = (low + high)>>1;
                if(height[i] > lest[mid]) low = mid+1;
                else high = mid-1; // has to write in this way, can not break when height[i] == lest[mid]
            }
            lest[low] = height[i];
        }
        l[i] = top;
    }
    top = 0;
    for(int i=N;i>=1;--i) {
        if(height[i] > rist[top]) {rist[++top] = height[i];}
        else
        {
            int low = 1,high = top;
            while(low<=high)
            {
                int mid = (low + high)>>1;
                if(height[i] > rist[mid]) low = mid+1;
                else high = mid-1;
            }
            rist[low] = height[i];
        }
        r[i] = top;
    }
    int in = 0;
    for(int i=1;i<N;++i)
        for(int j=i+1;j<=N;++j)
            in = max(in,l[i] + r[j]);
    cout<<(N - in)<<endl;
    return 0;
}
