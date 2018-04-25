### Graph
#### 1. [1860 Currency Exchange](http://poj.org/problem?id=1860) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201860.cpp)
> 有N种货币，M个交换点。每个交换点可以将两种货币互换。当前持有S种类货币若干，询问是否能够进行某些交换之后增加手上S种类货币数量。

* 单源正环查找, [spfa DFS判断负环](https://blog.csdn.net/wyh0410/article/details/53022155),[spfa 算法](https://blog.csdn.net/xunalove/article/details/70045815), [Bellmen-Ford 算法](https://blog.csdn.net/ak_lady/article/details/70147204)
* 则如果存在使得soruce货币增加的回路，回路上的点会被push进队列，则一定能够回到source节点。如果不存在使得source货币增加的路径，则肯定不存在一直循环增加的回路，那么队列肯定不会一直增长
 不会陷入死循环，判断source到source的环是否使得钱增加即可，若增加则直接返回true。
 
 #### 2. [3259 Wormholes](http://poj.org/problem?id=3259) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%203259.cpp)
 > 题意是问是否能通过虫洞回到过去；
虫洞是一条单向路，不但会把你传送到目的地，而且时间会倒退Ts。
我们把虫洞看成是一条负权路，问题就转化成求一个图中是否存在负权回路；

* [Bellmen-Ford 算法](https://github.com/HzhElena/POJ_solution/blob/master/POJ%203259(Bellmen).cpp)
* 我们考虑一个节点入队的条件是什么，只有那些在前一遍松弛中改变了距离估计值的点，才可能引起他们的邻接点的距离估计值的改变。因此，用一个先进先出的队列来存放被成功松弛的顶点。同样，我们有这样的定理：“两点间如果有最短路，那么每个结点最多经过一次。也就是说，这条路不超过n-1条边。”（如果一个结点经过了两次，那么我们走了一个圈。如果这个圈的权为正，显然不划算；如果是负圈，那么最短路不存在；如果是零圈，去掉不影响最优值）。也就是说，每个点最多入队n-1次（这里比较难理解，需要仔细体会，n-1只是一种最坏情况，实际中，这样会很大程度上影响程序的效率）。
* 有了上面的基础，思路就很显然了，加开一个数组记录每个点入队的次数（num），然后，判断当前入队的点的入队次数，如果大于n-1，则说明存在负权回路。
* 对于求单源负环或者正环，如果存在单一起点，使用 spfa 的 dfs 模式。如果不存在单一起点，使用spfa 的 bfs 遍历 或者 bellmen-ford 算法 (或者对于每一个节点作为起点进行 dfs )。此时可以随便指定一个起点。

#### 3. [1062 昂贵的聘礼](http://poj.org/problem?id=1062) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201062.cpp)
> 题目大意是说有N个物品，每个物品都有自己的价格，但同时某些物品也可以由其他的（可能不止一个）替代品，这些替代品的价格比较“优惠”，问怎么样选取可以让你的花费最少来购买到物品1

* 使用 dijkstra 算法，但是由于替换物品等级差不能超过M。需要枚举可以使用物品的区间，然后对于每一个区间使用 该算法进行计算。得到最小值即为最后解。

#### 4. [2253  Frogger](http://poj.org/problem?id=2253) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%202253.cpp)
> 寻找从出发点到终点所有路径中 路径中最长小段距离 最短的路径。

* 单源最短路径变种。使用dijkstra算法，只需要将distance 更新原则进行改变
* 原来是更新为距离最短，现在是更新为路径上最长边最短。

#### 5. [1125  Stockbroker Grapevine](http://poj.org/problem?id=1125) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201125.cpp)
> 可以从任意源点出发到达网络中所有节点的最短路径。

* floyd 算法，注意多个测试用例时，每次需要初始化为INF

#### 6. [2240  Arbitrage](http://poj.org/problem?id=2240) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%202240.cpp)
> 能不能通过各个国家汇率的不同赚到比当初更多的钱。

* 使用 bellmen-ford 判断环的存在

#### 7. [1789  Truck History](http://poj.org/problem?id=1789) / [Solution](https://github.com/HzhElena/POJ_solution/blob/master/POJ%201789.cpp)
> 最小生成树

* 使用 prime 算法，每次加入当前已经visit 过点到 未 visit 过点的最短距离点。 直到将所有点遍历为止。
