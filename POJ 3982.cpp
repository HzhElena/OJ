#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
// use char * is easier.
void add(char *a,char *b,char *c,char *ans)
{
    int aa[maxn] = {0},bb[maxn] = {0},cc[maxn] = {0},sum[maxn] = {0},pa = 0,pb = 0,pc = 0;
    int lena = strlen(a),lenb = strlen(b),lenc = strlen(c),len_sum = 0;

    for(int i=lena-1;i>=0;--i)
        aa[pa++] = a[i] - '0';
    for(int i=lenb-1;i>=0;--i)
        bb[pb++] = b[i] - '0';
    for(int i=lenc-1;i>=0;--i)
        cc[pc++] = c[i] - '0';

    int carry =0, len = max(lena,lenb);
    len = max(len,lenc);

    for(int i=0;i<len;++i)
    {
        int tmp = aa[i] + bb[i] + cc[i] + carry;
        sum[len_sum++] = tmp % 10;
        carry = tmp / 10;
    }
    if(carry) sum[len_sum++] = carry;

    int j = 0;
    for(int i=len_sum-1;i>=0;--i)
    {
        ans[j++] = sum[i]+'0';
    }
    ans[j] = '\0';
}
int main()
{
    char a[maxn],b[maxn],c[maxn],ans[maxn];
    while(cin>>a>>b>>c)
    {
        for(int i=0;i<25;++i){
            add(a,b,c,ans);
            add(b,c,ans,a);
            add(c,ans,a,b);
            add(ans,a,b,c);
        }
        cout<<ans<<endl;
    }
    return 0;
}
