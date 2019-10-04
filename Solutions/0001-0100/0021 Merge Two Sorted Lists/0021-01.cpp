//0021 Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* head = l1;  //insert l2 into l1
        ListNode* prev = NULL;
        while (l1 != NULL || l2 != NULL) {
        	if (l1 == NULL) {
        		if (prev == NULL) return l2;
        		else {
        			prev->next = l2;
        			return head;
        		}
        	}
        	else if (l2 == NULL) {
        		return head;
        	}
        	else {
        		if (prev == NULL) {
        			if (l1->val >= l2->val) {
	        			ListNode* tmp = l2->next;
	        			head = l2;
	        			prev = l2;
	        			l2->next = l1;
	        			l2 = tmp;
	        		}
	        		else {
	        			prev = l1;
	        			l1 = l1->next;
	        		}
        		}
        		else {
        			if (l1->val >= l2->val) {
	        			ListNode* tmp = l2->next;
	        			prev->next = l2;
	        			l2->next = l1;
	        			prev = l2;
	        			l2 = tmp;
	        		}
	        		else {
	        			prev = l1;
	        			l1 = l1->next;
	        		}
        		}	
        	}
        }
        return head;
    }
};
