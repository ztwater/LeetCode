# Union Find (10/28)

## Medium

**0130 Surrounded Regions**

	01 (97.34 87.50): 从边界DFS‘O’，没有访问到的地方置‘X’。

**0200 Number of Islands** *(91.75 12.36)*

**0399 Evaluate Division** [Discussion on LeetCode](https://leetcode.com/problems/evaluate-division/discuss/406566/C%2B%2B-Union-Find-0ms-9MB-(100-100))

	01 (100.00 100.00): 见讨论。

**0547 Friend Circles** *(82.75 81.82)*

**0684 Redundant Connection**

	01 (78.56 48.06): 使用并查集将连接的顶点放入同一个集合中，若在Union时发现两顶点在同一个集合中，则记录（使用这样的思想判断环）。

**0721 Accounts Merge**

	01 (96.65 58.82): 使用并查集合并同一个人的所有邮箱，使用了两个hashmap优化查找。

**0947 Most Stones Removed with Same Row or Column**

	01 (TLE): DFS

	02 (98.66 20.00): 使用并查集，这里的技巧是如何利用已有行列关系合并集合并计数。由于行列本身具有相等的关系，所以分别用一列数来表示，一共有不超过10000个石头，故将列表示为10000-19999，合并每个行和列的数值。注意最后统计数目的时候先进行路径压缩，统计所有行/列构成的集合数目。

**0959 Regions Cut By Slashes**

	01 (93.84 25.00): 把一个方格分成4块，使用并查集进行合并。

**0990 Satisfiability of Equality Equations** *(97.47 100.00)*

**1202 Smallest String With Swaps** 

	01 (65.63 100.00): 不同位置的字母经过任意次对换可得到其全排列，只需把同组对换的所有字母进行排序即可。

## Hard