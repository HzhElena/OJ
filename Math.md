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
 
#### 2. [Biorhythms](http://poj.org/problem?id=1006) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201006.cpp)
> 求满足 k%a == i1 k%b == i2 k%c == i3 的 最小k 

* [中国剩余定理](https://blog.csdn.net/d_x_d/article/details/48467255)的使用，
X被a,b,c处分别余r1,r2,r3。表示为：

X%a = r1                     x%b = r2                     x%c = r3

bc*k1 % a = 1     ac*k3 % b = 1     ab*k3 % c = 1

所以

x = bc * k1 * r1 + ac * k2 * r2 + ab * k3 * r3

最后关于 x 对于a b c 的最小公倍数求余
* 先求 bc 的倍数 使其关于 a 余1. 再乘以余数。 得到和后 求对于最小公倍数的余数。

#### 3. [Joseph](http://poj.org/problem?id=1012) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201012.cpp)
> 求满足 k%a == i1 k%b == i2 k%c == i3 的 最小k

* *约瑟夫环* 初始情况： 0, 1, 2 ......n-2, n-1 (共n个人)形成环，每次从1报数，报到m 的人出列。

设第一个出列的为第k个人，下标为k-1. 出列之后，

剩下的n-1个人组成了一个新的约瑟夫环（以编号为k==m%n的人开始）:

 k  k+1  k+2  ... n-2, n-1, 0, 1, 2, ...,k-3, k-2 

现在我们把他们的编号做一下转换：
 
x' -> x

k     --> 0

k+1   --> 1

k+2   --> 2

...

...

k-2   --> n-2

k-1   --> n-1

变换后就完完全全成为了(n-1)个人报数的子问题，假如我们知道这个子问题的解：例如x是最终的胜利者，那么根据上面这个表把这个x变回去不刚好就是n个人情况的解吗！即已知在 n-1 子问题下最后剩下来的人的下标可以推出在 n 问题下最后胜者的下标

x ->ｘ＇？(这正是从n-1时的结果反过来推n个人时的编号！)

0 -> k

1 -> k+1

2 -> k+2

...

...

n-2 -> k-2

变回去的公式　x'=(x+k)%n
递推公式， f[i] 代表剩下 i 个人时胜者的下标。

```+python
f[1]=0;

f[i]=(f[i-1]+k)%i = (f[i-1] +m%i) % i = (f[i-1] + m) % i ;  (i>1)
```
若下表为 1,2,3，...n 从1开始，则最后算出结果加一即可。
*  本题是约瑟夫环变形 先引入Joseph递推公式，设有n个人下标为（0,...,n-1），数m，则第i轮出局的人为f(i)=(f(i-1)+m-1)%(n-i+1),f(0)=0; f(i) 表示当前子序列中要退出的那个人（当前序列编号为0~(n-i));
此时求出的 f(i) 并不是原始下标，而是每一次环的第 f(i) 各元素。保持原来下标不变。但是并不是加一的关系。序列内元素的相对顺序不变。

拿个例子说：K=4,M=30;

f(0)=0;

f(1)=(f(0)+30-1)%8=5; 序列（0,1,2,3,4,5,6,7）中的5

f(2)=(f(1)+30-1)%7=6; 序列（0,1,2,3,4,6,7）中的7

f(3)=(f(2)+30-1)%6=5; 序列（0,1,2,3,4,6）中的6

f(4)=(f(3)+30-1)%5=4; 序列（0,1,2,3,4）中的4

........

依据题意，前K个退出的人必定是后K个人，所以只要前k轮中只要有一次f(i)<k则此m不符合题意。

