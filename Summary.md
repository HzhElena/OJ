# Summary of [POJ](http://poj.org/problemlist) solutions
Recorded according to problem category
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

