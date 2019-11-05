# Graph (14/36)

## Easy

**0997 Find the Town Judge** (77.84 100.00)

**1042 Flower Planting With No Adjacent** 

	01 (89.55 100.00): 注意此题不是CSP，因为不会产生无法解决的冲突，使用邻接表存储相邻边，保证相邻边数字不同即可。

## Medium

**0133 Clone Graph**

	01 (72.06 6.67): 为每个节点提供一个中间整数作为映射，发现并不是必须的。

	02 (94.36 100.00): 使用一个hashmap就可以完成深复制的进行。

**0399 Evaluate Division**

**0684 Redundant Connection**

	01 (78.56 48.06): 使用并查集将连接的顶点放入同一个集合中，若在Union时发现两顶点在同一个集合中，则记录（使用这样的思想判断环）。

**0743 Network Delay Time**

	01 (88.20 94.40): Dijkstra

**0785 Is Graph Bipartite?** 

	01 (79.49 38.46): BFS

**0802 Find Eventual Safe States** 

	01 (92.54 100.00): 每个节点视为一个状态机，只有当其所有子树都为终态时才为终态。

**0841 Keys and Rooms** (65.92 100.00)

**0959 Regions Cut By Slashes**

	01 (93.84 25.00): 把一个方格分成4块，使用并查集进行合并。

**0990 Satisfiability of Equality Equations**

**1043 Partition Array for Maximum Sum**

	01 (10.98 100.00): DP，使用了二维数组记录从任意起点到任意重点的最大和。

	02 (96.19 100.00): DP，只需要从一个方向进行运算，检查后1，2，...，K项的组合是否会有最大值即可，而且只需要一位数组进行存储。

**1161 Maximum Level Sum of a Binary Tree** 

	01 (77.82 100.00): 使用两个队列交替进行BFS，计算每层的和。

	Other Solutions: 1. 使用DFS也可以实现；2. 可以只使用一个队列，但是需要记录本层元素的数目。

## Hard

**0765 Couples Holding Hands**

	01 (61.10 84.62)