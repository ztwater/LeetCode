# Two Pointers (43/58)

## Easy

**0026 Remove Duplicates from Sorted Array** *(93.32 93.75)*

**0027 Remove Element** *(70.60 67.65)*

**0028 Implement strStr()** `KMP`

	01 (90.36 37.14): 实现了KMP算法用于子串的搜索，了解了BM算法和Sunday算法的原理。

**0088 Merge Sorted Array** *(84.05 73.91)*

**0125 Valid Palindrome** *(99.20 100.00)*

**0141**

**0167 Two Sum II - Input array is sorted** *(96.84 78.43)*

**0234**

**0283 Move Zeroes** *(99.90 90.28)*

**0344 Reverse String** *(92.05 100.00)*

**0345 Reverse Vowels of a String** *(61.75 69.70)*

**0349 Intersection of Two Arrays** 

	01 (19.07 60.00): 使用hashset去重取交 

	02 (99.29 86.67): 先对数组进行排序，再取交集 

**0350 Intersection of Two Arrays II** *(74.14 82.14)*

**0532 K-diff Pairs in an Array** *(95.83 100.00)*

**0844 Backspace String Compare** *(61.95 72.73)*

**0925 Long Pressed Name** *(100.00 85.71)*

**0977 Squares of a Sorted Array** *(94.82 98.65)*

**1213**

## Medium

**0011 Container With Most Water** *(65.36 100.00)*

**0016 3Sum Closest** 

	01 (79.84 100.00): 取一个元素出来，用双指针逼近差值，时间复杂度O(n^2)。

**0018 4Sum** [Discussion on LeetCode](https://leetcode.com/problems/4sum/discuss/402122/c-4ms-beats-99-two-pointers-2)

	01 (99.84 80.70 80min): 外侧双指针从两侧逼近，中间边界单侧分别固定，内侧双指针求解，以此类推。详见讨论。

**0019 Remove Nth Node From End of List** *(100.00 98.68 10min)*

**0075 Sort Colors** *(69.51 89.47)*

**0080 Remove Duplicates from Sorted Array II** *(98.90 84.21)*

**0086 Partition List** *(97.05 70.83)*

**0209 Minimum Size Subarray Sum** *(96.76 100.00)*

**0287 Find the Duplicate Number** *(97.45 100.00)* `Floyd Cycle Detection` 

**0424 Longest Repeating Character Replacement** `Sliding Window`

	01 (8.53 6.90): 每个字母使用一个队列进行存储替换的字母。

	02 (92.83 52.65): 组成最长串的字母如果不是当前字母，则左边界后移。

**0524 Longest Word in Dictionary through Deleting** *(67.11 92.31)*

**0567 Permutation in String** `Sliding Window`

	01 (95.49 100.00): 题目的关键是如何表示字符串的排列，这里不需要给出字符串的各个排列并比较，而是可以直接检查每个字符出现的次数进行判断，之后利用Sliding Window的思想解决问题即可。

**0713 Subarray Product Less Than K**

	01 (66.29 60.00 28min): 计数的过程实现得较为复杂，在start端前移时进行的计算，可以参考答案进行改进。

	02 (87.30 60.00): 在end端前移时进行计数。

**0763 Partition Labels** `Greedy`

	01 (92.01 32.26): 思路是从当前段所有字符最后一次出现的地方进行分割，故首先计算所有字符最后出现的位置，在遍历中不断扩大当前段长度。

	02 (92.01 100.00): 题目中给了限定，只使用26个小写字母，故只需要一个数组便可以存储所有数据。

**0826 Most Profit Assigning Work**

	01 (31.24 27.27): 使用map存储	<profit, difficulty>对，对工人能力排序，从大到小比较。相似的方法包括使用priority_queue，或直接使用pair和自定义排序函数， 在讨论区看到了可以使用BST解决的想法，也值得尝试。

	02 (46.06 9.09): 使用桶排序（bucket sort)。

	03 (94,59 45.45): 使用优化后的排序算法。

**0838 Push Dominoes** *(99.40 25.00)*

**0845 Longest Mountain in Array** *(98.34 14.29 33min)*

**0881 Boats to Save People** *(83.53 100.00)*

**0904 Fruit Into Baskets** *(82.81 58.06)* `->0424`

**0923 3Sum With Multiplicity** 

	01 (21.27 100.00 42min): 三指针解法。由于数的范围给定（0～300），故可以先统计个数，再通过排列组合计算。

**0930 Binary Subarrays With Sum** *(98.33 60.00)*

**0986 Interval List Intersections** *(76.77 24.00)*

**1004 Max Consecutive Ones III** *(23.96 9.09)* `Sliding Window`

**1093 Statistics from a Large Sample**  *(84.27 100.00)*

## Hard

**0044 Trapping Rain Water** 

	01 (95.86 91.14): 首先从左到右找到一个“坑”，然后从找到“右壁”（高于“左壁”或着右侧最高）,之后计算中间的水坑面积。

	02 Optimum Solution: 在一侧壁高于另一侧时，只有“短板”起作用
