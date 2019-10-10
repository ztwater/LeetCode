//0086 Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;
        ListNode* low = NULL;
        ListNode* high = NULL;
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        while (head != NULL) {
            ListNode* p = head->next;
        	if (head->val < x) {
        		if (low == NULL) {
        			p1 = head;
                    head->next = NULL;
        			low = p1;
        		}
        		else {
        			p1->next = head;
                    head->next = NULL;
        			p1 = p1->next;
        		}
        	}
        	else {
        		if (high == NULL) {
        			p2 = head;
                    head->next = NULL;
        			high = p2;
        		}
        		else {
        			p2->next = head;
                    head->next = NULL;
        			p2 = p2->next;
        		}
        	}
        	head = p;
        }
        if (p1 != NULL) {
        	p1->next = high;
        	return low;
        }	
        else {
        	return high;
        }
    }
};