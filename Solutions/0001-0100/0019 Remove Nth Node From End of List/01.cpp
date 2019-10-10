//0019 Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if (head == NULL) return NULL;
    	ListNode* end = head;
        for (int i = 0; i < n; i++) {
        	end = end->next;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (end != NULL) {
        	pre = cur; 
        	cur = cur->next;
        	end = end->next;
        }
        if (pre == NULL) head = head->next;
        else pre->next = cur->next;
        return head;
    }
};