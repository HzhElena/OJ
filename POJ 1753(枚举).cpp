#include <iostream>
#include <climits>
#include <cstdio>
#include <queue>
using namespace std;
// 结果为 0 或者 binary (11111 11111 11111) = 1<<16 -1
const int maxn = (1<<16)-1;
// 翻转
int change(int state,int pos)
{
    int k;
    //使用异或操作，若k对应位为1 则改变为0
    k = 1<<pos;
    state ^= k;
    if(pos>3) {k = 1<<(pos-4); state ^= k;}
    if(pos<12) {k = 1<<(pos+4); state ^=k;}
    if(pos%4 != 0) {k = 1<<(pos-1); state ^= k;}
    if(pos%4 != 3) {k = 1<<(pos+1); state ^= k;}
    return state;
}
bool enumerate(int result,int remain,int start)
{
    int tmp = 17-remain;
    if(remain == 0) return (result == 0 || result == maxn);
    if(remain == 1)
    {
        for(int i=start;i<tmp;++i){
            int res = change(result,i);
            if(res == 0 || res == maxn) return true;
        }
        return false;
    }
    else{
        for(int i=start;i<tmp;++i){
            int res = change(result,i);
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
        if(c == 'b')  start += (1<<i);
    }
    for(i=0;i<17;++i)
    {
        bool flag = enumerate(start,i,0);
        if(flag) break;
    }
    if(i > 16) cout<<"Impossible"<<endl;
    else cout<<i<<endl;
    return 0;
}
