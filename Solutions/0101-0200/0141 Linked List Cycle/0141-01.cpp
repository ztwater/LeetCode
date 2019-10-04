//0141 Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* cur = head;
        int i = 0;
        while (cur != NULL) {
        	ListNode* pre = head;
        	int j = 0;
        	while (cur != pre) {
        		pre = pre->next;
        		j++;
        	}
        	if (i != j) {
        		return true;
        	}
        	i++;
        	cur = cur->next;
        }
        return false;
    }
};