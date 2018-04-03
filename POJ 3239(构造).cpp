#include <iostream>

using namespace std;
void print(int sta,int en)
{
    for(int i=sta;i<=en;i+=2)
    {
        cout<<i<<" ";
    }
}
int main()
{
    int n,m;
    while(cin>>m && m>0)
    {
        bool mOdd = (m%2 == 1);
        if(m%6!=2 && m%6!=3)
        {
            if(!mOdd)
            {
                print(2,m);
                print(1,m-1);
            }
            else{
                print(2,m-1);
                print(1,m);
            }
        }
        else
        {
            n = m/2;
            bool nOdd = (n%2 == 1);
            if(!nOdd && !mOdd)
            {
                print(n,m);
                print(2,n-2);
                print(n+3,m-1);
                print(1,n+1);
            }
            else if(!mOdd && nOdd)
            {
                print(n,m-1);
                print(1,n-2);
                print(n+3,m);
                print(2,n+1);
            }
            else if(mOdd && !nOdd)
            {
                print(n,m-1);
                print(2,n-2);
                print(n+3,m-2);
                print(1,n+1);
                print(m,m);
            }
            else
            {
                print(n,m-2);
                print(1,n-2);
                print(n+3,m-1);
                print(2,n+1);
                print(m,m);
            }
        }
        cout<<endl;
    }
    return 0;
}
