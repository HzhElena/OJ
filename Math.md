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
 
#### 1. [Biorhythms](http://poj.org/problem?id=1006) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201006.cpp)
> 求满足 k%a == i1 k%b == i2 k%c == i3 的 最小k 

* [中国剩余定理](https://blog.csdn.net/d_x_d/article/details/48467255)的使用，
X被a,b,c处分别余r1,r2,r3。表示为：

X%a = r1                     x%b = r2                     x%c = r3

bc*k1 % a = 1     ac*k3 % b = 1     ab*k3 % c = 1

所以

x = bc * k1 * r1 + ac * k2 * r2 + ab * k3 * r3

最后关于 x 对于a b c 的最小公倍数求余
* 先求 bc 的倍数 使其关于 a 余1. 再乘以余数。 得到和后 求对于最小公倍数的余数。

 
