# Summary of [POJ](http://poj.org/problemlist) solutions
Recording according to [problem category](https://blog.csdn.net/lyy289065406/article/details/78702485)
## 基本算法
### 枚举
#### 1. [1753 Flip Game](http://poj.org/problem?id=1753) / [Solution](https://github.com/HzhElena/OJ/blob/master/POJ%201753(%E6%9E%9A%E4%B8%BE).py)
* 使用递归从反转0个棋子到1,2,...,16个逐步查找，如果可以达到目标状态则立刻返回步数。
* 使用 int 表示状态
* 最多 2^16 状态，因此可以使用枚举法
#### 1. [2965 The Pilots Brothers' refrigerator](http://poj.org/problem?id=2965) / [Solution](https://github.com/HzhElena/OJ/blob/master/POJ%202965(%E6%9E%9A%E4%B8%BE).py)
> 一个冰箱有4*4矩阵排列的一共16个把手(handles)，每个把手只有'+'(关)和'-'(开)两种状态，当且仅当开关全部为'-',也即冰箱把手都为开启状态的时候冰箱才能被打开。搬动冰箱把手定义一种翻转，即：每次随机选取一个把手翻动，则其所在行和所在列的一共7个把手全部翻转。现在给出16个把手的初始状态（至少有一个把手为'+'），求至少翻动多少轮次，才能够把冰箱门打开，也即把手状态全部为'-'。
输出：达到冰箱开启，即全部把手状态为'-'的最小轮次。首行输出轮次，以下每行输出按次翻动的把手的行号和列号（之间用随意多个空格隔开即可）。

* 使用递归从反转0个门把手到1,2,...,16个逐步查找，如果可以达到目标状态则立刻返回步数。
* 使用 int 表示状态
* 最多 2^16 状态，因此可以使用枚举法。使用枚举法记录转动的把手行号和列号更加方便。
## Search
### BFS
#### 1. [1753 Flip Game](http://poj.org/problem?id=1753) / [Solution](https://github.com/HzhElena/OJ/blob/master/POJ%201753(BFS).py)
    > 有一4x4棋盘，上面有16枚双面棋子（一面为黑，一面为白）， 
     当翻动一只棋子时，该棋子上下左右相邻的棋子也会同时翻面。 
     以b代表黑面，w代表白面，给出一个棋盘状态， 
     问从该棋盘状态开始，使棋盘变成全黑或全白，至少需要翻转多少步   
* Bit operation ^= 异或操作符 使得int中某一特定位变为1 或 0。
* Use (step>16) to break loop 否则会无穷地循环下去。 
* BFS 内部每一个状态均翻转16个位。


