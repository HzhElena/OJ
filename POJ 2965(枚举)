#include <iostream>
#include <queue>
using namespace std;
int ans[20][2];
void flip(int &state,int pos)
{
    state ^= (1<<pos);
    int row = pos/4,col = pos%4;
    for(int i=0;i<4;++i)
    {
        int tmp = 4*i + col,tmp2 = row*4 + i;
        if(tmp != pos) state ^= (1<<tmp);
        if(tmp2 != pos) state ^= (1<<tmp2);
    }
}
bool enumerate(int result,int remain,int start)
{
    if(remain == 0) return (result == 0);
    int tmp = 17-remain;
    for(int i=start;i<tmp;++i)
        {
            int res = result;
            flip(res,i);
            ans[remain][0] = i/4;
            ans[remain][1] = i%4;
            if(remain == 1)
            {
                if(res == 0) return true;
            }
            else{
                if(enumerate(res,remain-1,i+1)) return true;
            }
        }
    return false;
}
int main()
{
    char c;
    int start = 0,i;
    for(int i=0;i<16;++i)
    {
        cin>>c;
        if(c == '+') start += (1<<i);
    }
    for(i=0;i<17;++i)
    {
        bool flag = enumerate(start,i,0);
        if(flag) break;
    }
    cout<<i<<endl;
    for(int j=i;j>=1;--j)
        cout<<ans[j][0]+1<<" "<<ans[j][1]+1<<endl;
    return 0;
}
