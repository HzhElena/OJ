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

#### 2. [1321 棋盘问题](http://poj.org/problem?id=1321) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201321(DFS).cpp)
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
%ld用于long类型，%lld用于long long类型。
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
