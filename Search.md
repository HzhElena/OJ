# Search Problems
### DFS
#### 1. [2488 A Knight's Journey](http://poj.org/problem?id=2488) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%202488(DFS).cpp)
> 输入棋盘大小 p * q, q 列为字母表示，p 行为数字表示。每次走一步必须在某方向走两步，垂直方向走一步。求不重复遍历一遍棋盘所有点的字典序最小路径。

* 使用 DFS, 由于是不重复遍历，应该用到回溯。
* 对于字典序最短路径，要求我们寻找的时候起始点应该按照字典序查找，并且每一步走的方向应该按字典序最小。
* 保存结果：维护result[], 每次dfs 更新 result[k]. 如果找到符合要求的路径，立即return true.
