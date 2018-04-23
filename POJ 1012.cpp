#include <iostream>

using namespace std;

int main()
{
    int res[20] = {0};
    int k,n;
    while(cin>>k && k!=0)
    {
        if(res[k] != 0) {cout<<res[k]<<endl; continue;}
        int cur = 0,m = 1;
        n = 2*k; // total person number
        for(int i=1;i<=k;++i)
        {
            cur = (cur + m-1) % (n-i+1);
            if(cur < k) {
                ++m;
                cur = 0;
                i = 0;
            }
        }
        res[k] = m;
        cout<<m<<endl;
    }
    return 0;
}
