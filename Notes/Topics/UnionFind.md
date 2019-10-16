# Union Find (5/28)

## Medium

**0399 Evaluate Division** [Discussion on LeetCode](https://leetcode.com/problems/evaluate-division/discuss/406566/C%2B%2B-Union-Find-0ms-9MB-(100-100))

	01 (100.00 100.00): 见讨论。

**0547 Friend Circles** *(82.75 81.82)*

**0684 Redundant Connection**

	01 (78.56 48.06): 使用并查集将连接的顶点放入同一个集合中，若在Union时发现两顶点在同一个集合中，则记录（使用这样的思想判断环）。

**0947 Most Stones Removed with Same Row or Column**

	01 (TLE): DFS

	02 (98.66 20.00): 使用并查集，这里的技巧是如何利用已有行列关系合并集合并计数。由于行列本身具有相等的关系，所以分别用一列数来表示，一共有不超过10000个石头，故将列表示为10000-19999，合并每个行和列的数值。注意最后统计数目的时候先进行路径压缩，统计所有行/列构成的集合数目。

**0959 Regions Cut By Slashes**

	01 (93.84 25.00): 把一个方格分成4块，使用并查集进行合并。

## Hard