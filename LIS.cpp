//最长上升子序列nlogn算法
#include <iostream>
using namespace std;
const int maxn = 100;
int st[maxn]; // 单调递增栈
int a[] = {2, 1, 5, 3 ,6 ,4, 8, 9, 7};
int LIS(int n)
{
    int top = 0;
    st[0] = -1;
    for(int i=0;i<n;++i)
    {
        if(a[i] > st[top]) {st[++top] = a[i];}
        else
        {
            int low = 0,high = top;
            while(low<=high)
            {
                int mid = (low + high) >> 1;
                if(st[mid] < a[i]) low = mid+1;
                else high = mid-1;
            }
            st[low] = a[i];
        }
    }
    cout<<top<<endl;
    for(int i=1;i<=top;++i)
        cout<<st[i]<<" ";
    cout<<endl;
    return (top);
}
int main()
{
    cout<<LIS(9);
    return 0;
}
