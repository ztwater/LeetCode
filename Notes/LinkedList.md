# Linked List (9/36)

## Easy (9/10)

**0021 Merge Two Sorted Lists**

*01 (76.97 92.62):* 首先进行特殊情况的处理。

**0083 Remove Duplicates from Sorted List**

*01 (71.81 100.00):* 尽可能的用更少的临时指针。

**0141 Linked List Cycle (also with tag `<two pointers>`)**

*01 (6.35 76.32):* 每访问一个节点，从头遍历一遍，若地址相同跳出。

*02 (73.05 93.42):* 发现该问题为双指针问题，使用快慢指针进行解决。

**0160 Intersection of Two Linked Lists**

*01 (55.99 16.67):* 使用hash表进行存储（C++中为unorder_set），本来的想法是把第二个链表反向连接在第一个链表上，然后判断是否有环，题目不让对原链表进行操作，只能选取别的办法。

*02 (94.40 77.80):* 如果有先交点的话，两链表后续是一样的，所以可以从剩余长度相同处开始比较。

**0203 Remove Linked List Elements**

*01 (94.86 79.25)*

**0206 Reverse Linked List**

*01 (76.95 92.37):* 迭代方法解决。

*02 (98.88 29.01):* 使用栈（递归）进行解决。

**0234 Palindrome Linked List**

*01 (67.09 91.38):* 翻转后一半的链表，注意不要让两链表汇合，会回收两次导致heap-use-after-free错误 。

*02 (97.99 91.38):* 使用双指针可以不用计数而获取链表的一半。

**0237 Delete Node in a Linked List**

*01 (80.37 73.08)* 

**0876 Middle of the Linked List**

*01 (55.46 93.22):* 使用双指针。

## Medium (0/24)

## Hard (0/2)