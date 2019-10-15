# Graph (5/36)

## Easy

**0997 Find the Town Judge** *(77.84 100.00)*

**1042 Flower Planting With No Adjacent** 

	01 (89.55 100.00): 注意此题不是CSP，因为不会产生无法解决的冲突，使用邻接表存储相邻边，保证相邻边数字不同即可。

## Medium

**0684 Redundant Connection**

	01 (78.56 48.06): 使用并查集将连接的顶点放入同一个集合中，若在Union时发现两顶点在同一个集合中，则记录（使用这样的思想判断环）。

**0959 Regions Cut By Slashes**

	01 (93.84 25.00): 把一个方格分成4块，使用并查集进行合并。

**1161 Maximum Level Sum of a Binary Tree** 

	01 (77.82 100.00): 使用两个队列交替进行BFS，计算每层的和。

	Other Solutions: 1. 使用DFS也可以实现；2. 可以只使用一个队列，但是需要记录本层元素的数目。

## Hard