### Graph
#### 1. [1860 Currency Exchange](http://poj.org/problem?id=1860) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201860.cpp)
> 有N种货币，M个交换点。每个交换点可以将两种货币互换。当前持有S种类货币若干，询问是否能够进行某些交换之后增加手上S种类货币数量。

* 单源正环查找, [spfa DFS判断负环](https://blog.csdn.net/wyh0410/article/details/53022155),[spfa 算法](https://blog.csdn.net/xunalove/article/details/70045815), [Bellmen-Ford 算法](https://blog.csdn.net/ak_lady/article/details/70147204)
* 则如果存在使得soruce货币增加的回路，回路上的点会被push进队列，则一定能够回到source节点。如果不存在使得source货币增加的路径，则肯定不存在一直循环增加的回路，那么队列肯定不会一直增长
 不会陷入死循环，判断source到source的环是否使得钱增加即可，若增加则直接返回true。
 
 
 
