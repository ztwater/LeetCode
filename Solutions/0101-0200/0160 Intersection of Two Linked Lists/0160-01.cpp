//160. Intersection of Two Linked Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        unordered_set<ListNode*> set;
        ListNode* cur = headA;
       	while (cur != NULL) {
       		set.insert(cur);
       		cur = cur->next;
       	}
       	cur = headB;
       	auto end = set.end();
       	auto res = set.find(cur);
       	while (cur != NULL) {
       		if (res != end) return cur;
       		cur = cur->next;
       		res = set.find(cur);
       	}
       	return NULL;
    }
};