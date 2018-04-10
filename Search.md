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

