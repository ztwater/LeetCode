//203. Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
    	if (head == NULL) return NULL;
    	while (head->val == val) {
    		if (head->next == NULL) return NULL;
    		head = head->next;
    	}
    	if (head->next == NULL) return head;
    	ListNode* pre = head;
    	ListNode* cur = head->next;
    	while (cur != NULL) {
    		if (cur->val == val) {
    			pre->next = cur->next;
    			cur = cur->next;
    		}
    		else {
    			pre = cur;
    			cur = cur->next;
    		}
    	}
    	return head;
    }
};