# Math Problems
### Prime number
#### 1. [Dirichlet's Theorem on Arithmetic Progressions](http://poj.org/problem?id=3006) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%203006.cpp)
> 输入棋盘大小 p * q, q 列为字母表示，p 行为数字表示。每次走一步必须在某方向走两步，垂直方向走一步。求不重复遍历一遍棋盘所有点的字典序最小路径。

* 由于会有很多输入。可以生成素数表，对于每一个用例都是用该素数表。
* 素数筛选法可以快速生成素数表。方法是从2开始，对每个目前还标记为素数的数（初始情况下每个数都标记为素数），把它的所有倍数都标记为非素数。
这些扫描过去后，一直没被标记的（即保持为素数的）就是所有的素数。生成素数表的原理是对于每一个非素数，均存在素数为其因数。
* 找到a,a+d,a+2d...数列中的第n个素数，已经保证最大答案不超过1000000
```+python
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    int m=(int)sqrt(maxn+0.5);
    for(int i=2;i<m;++i)
    {
        if(isprime[i]){
            for(int j=2;j*i<maxn;++j)
                isprime[i*j] = false;
        }
    }
```