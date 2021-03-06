# Search Problems
### DFS
#### 1. [2488 A Knight's Journey](http://poj.org/problem?id=2488) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%202488(DFS).cpp)
> 输入棋盘大小 p * q, q 列为字母表示，p 行为数字表示。每次走一步必须在某方向走两步，垂直方向走一步。求不重复遍历一遍棋盘所有点的字典序最小路径。

* 使用 DFS, 由于是不重复遍历，应该用到回溯。
* 对于字典序最短路径，要求我们寻找的时候起始点应该按照字典序查找，并且每一步走的方向应该按字典序最小。
* 保存结果：维护result[], 每次dfs 更新 result[k]. 如果找到符合要求的路径，立即return true.

#### 2. [3009 Curling 2.0](http://poj.org/problem?id=3009) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%203009(DFS).cpp)
> 就是要求把一个冰壶从起点“2”用**最少的步数**移动到终点“3”. 其中0为移动区域，1为石头区域，冰壶一旦想着某个方向运动就不会停止，也不会改变方向（想想冰壶在冰上滑动），除非冰壶撞到石头1 或者 到达终点 3. 并且每次碰到石头后，该石头消失，冰壶静止，等待下一运动。最小步数不大于10，若大于10或者不存在输出-1。输出最小步数

* 由于每次运动后会改变 maze 状态，虽然为求最短路径，不适合用bfs.
* 使用 dfs, 需要注意使用 最小步数不大于10 这一条件进行剪枝。
* 每次运动冰壶之后，需要判断冰壶的状态是否有效，否则 直接return.
* 维护全局变量 result, 每当到达目的地，更新result值。

#### 3. [1321 棋盘问题](http://poj.org/problem?id=1321) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201321(DFS).cpp)
> 在一个给定形状 n*n 的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。

* 由于 不可以是同行同列， dfs 循环参数为 行。 vis 记录各列是否有数。
* 与其他题目区别在于可以直接跳过某一行。 并且当填满 k 个位置之后，增加一个解。

### BFS
#### 1. [3278 Catch That Cow](http://poj.org/problem?id=3278) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%203278(BFS).cpp)
> 位于 N (0<=N<=100000)处的农场主需要抓到位于 K (0<=K<=100000) 处的 牛。每一次坐标只能 +1 -1 或者 *2. 计算最少需要时间

* 需要用 vis 记录已经遍历过的 坐标，每次加入新坐标时进行判断。
* 不需要额外考虑0的情况！！ 因为通过+1 后*2 也会变成正常情况

#### 2. [1426 Find The Multiple](http://poj.org/problem?id=1426) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201426(DFS).cpp)
> 求 n 的倍数，该倍数仅由1 0构成。 结果最多 100 位

* 使用 DFS, 使用 BFS 超时。 
* 搜索到含有20位时，回溯
* 使用 unsigned __int64 强制指定类型为无符号64位. printf("%I64u\n",t); 在printf中%d用于int或者比int小的整数类型。比int小的类型被转型成int。
%ld用于long类型，%lld用于long long类型。 scanf double 用 %lf , printf double 用%f 。 scanf %f 为读取 float
* C++标准规定的是每个算术类型的最小存储空间，但其并不阻止编译器用更大的存储空间。如果要保证移植性，尽量用__int16 __int32 __int64吧，或者自己typedef int INT32一下。

数据类型名称	字节数	别名	取值范围

int	*	signed,signed int	由操作系统决定，即与操作系统的＂字长＂有关

unsigned int	*	unsigned	由操作系统决定，即与操作系统的＂字长＂有关

__int8	1	char,signed char	–128 到 127

__int16	2	short,short int,signed short int	–32,768 到 32,767

__int32	4	signed,signed int	–2,147,483,648 到 2,147,483,647

__int64	8	无	–9,223,372,036,854,775,808 到 9,223,372,036,854,775,807

bool	1	无	false 或 true

char	1	signed char	–128 到 127

unsigned char	1	无	0 到 255

short	2	short int,signed short int	–32,768 到 32,767

unsigned short	2	unsigned short int	0 到 65,535

long	4	long int,signed long int	–2,147,483,648 到 2,147,483,647

long long	8	none (but equivalent to __int64)	–9,223,372,036,854,775,808 到 9,223,372,036,854,775,807

unsigned long	4	unsigned long int	0 到 4,294,967,295

enum	*	无	由操作系统决定，即与操作系统的＂字长＂有关

float	4	无	3.4E +/- 38 (7 digits)

double	8	无	1.7E +/- 308 (15 digits)

long double	8	无	1.7E +/- 308 (15 digits)

wchar_t	2	__wchar_t	0 到 65,535

#### 3. [3126 Prime Path](http://poj.org/problem?id=3126) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%203126(BFS).cpp)
> 给定两个4位素数a b，求a变换到b最少需要几步，并且变换时只有一个数字不同，并且是素数

* 由于求最短路径，用 BFS
* 首先求出4位整数的 isprime 
* BFS中 用vis和 isprime 剪枝

#### 4. [3414 Pots](http://poj.org/problem?id=3414) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%203414(BFS).cpp)
> 有二个水壶，对水壶有三种操作：1)FILL(i)，将i水壶的水填满；
2)DROP(i)，将水壶i中的水全部倒掉；
3)POUR(i,j)将水壶i中的水倒到水壶j中，若水壶 j 满了，则 i 剩下的就不倒了，问最少进行多少步操作，并且怎么操作，输出操作的步骤，两个水壶中的水可以达到C这个水量。如果不可能则输出impossible。初始时两个水壶是空的，没有水。 

* 由于求最短路径，用 BFS
* 由于需要输出操作路径, 可以在 node 里定义 *pre ，由于 node 的唯一性，可以确定 路径。需注意用到指针时，需要保存所有节点
* 可以直接定义 pre_x[a][b] pre_y[a][b] 数组，每次保存上一个节点信息。

#### 5. [2251 Dungeon Master](http://poj.org/problem?id=2251) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%202251(BFS).cpp)
> 三维空间内，从 S 走到 E 最短路径

#### 6. [2362 Square](http://poj.org/problem?id=2362) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%202251(BFS).cpp)
> 给定若干根木棒，用所有的木棒是否可以拼成正方形？

* 如果木棒数目没有到达四根，则为no
* 比较容易想到的一点，如果当前木棒总长不是4的整数倍，则为no
* 由于木棒不能这段，如果最长的木棒大于边长，则为no
* 由于越短的木棒灵活性越高，进行快排之后由大至小进行搜索。
* 为了避免重复搜索，我们默认组成同一边时，下一根取的木棒长度必定不大于当前根的木棒。故设置变量frm，即当前可取木棒长度的范围。
* 组成不同边时，仍可以从最大边开始搜索

### 剪枝
#### 1. [1010 STAMPS](http://poj.org/problem?id=1010) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201010(DFS%2B%E5%89%AA%E6%9E%9D).cpp)
> 给你一些邮票的面值，然后给你一些顾客给出的价钱，求出邮票的组合来满足每一位顾客，要求是最多四张邮票，每张可以用多次（其实最多也就四次，因为要求最多四张，否则就是none）。由于每次有多种组合，那么如何取结果呢？
如果这些组合都能满足用户的的需求，那么
1.选种类最多的
2.如果种类相同，选总数最多的
3.如果总数相同，选邮票值组合最大值最大的那一组
4.如果连最大值也相同，那么就是tie
5。如果没有这样的组合，也就是不能用4张以内的邮票满足顾客，那么就是none
输出格式，第一个是总价值，括号里面的是邮票的种类，后面是相应的值。

* 使用 DFS 遍历所有解，并且更新最佳解
* 设定 bool none, tie 表示是否无解或者有多个相同解
* 将邮票按照价钱排序，每次dfs下一步仅能取当前邮票或者之后的邮票。因此可以剪枝，不会出现重复情况，按序遍历，无需记录vis情况。
* 记录使用邮票的index，因为不同种类的邮票可能有相同的价钱，但仍视为不同种类。
#### 1. [1129 Channel Allocation](http://poj.org/problem?id=1129) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201129(%E8%BF%AD%E4%BB%A3%E6%B7%B1%E6%90%9C).cpp)
> 当一个广播电台在一个非常大的地区，广播站会用中继器来转播信号以使得每一个接收器都能接收到一个强烈的信号。然而，每个中继器必须慎重选择使用，使相邻的中继器不互相干扰。如果相邻的中继器使用不同的频道，那么就不会相互干扰。由于无线电频道是一有限的，一个给定的网络所需的中继频道数目应减至最低。编写一个程序，读取一个中继网络，然后求出需要的最低的不同频道数. 即相当于涂色问题，邻接点需要不同颜色，最少需要的颜色数

* 对于这题数据范围很小（节点最多26个），所以使用普通的暴力搜索法即可
* 对点i的染色操作：从最小的颜色开始搜索，当i的直接相邻（直接后继）结点已经染过该种颜色时，搜索下一种颜色。
* 四色定理：任何一张地图只用四种颜色就能使具有共同边界的国家着上不同的颜色。因此可以用 超过四种颜色作为剪枝
* 此题可以利用四色定理[直接验证答案](https://www.cnblogs.com/candy99/p/5923629.html)，分别使用1到4种颜色是否可行。
