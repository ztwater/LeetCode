//0234.Palindrome Linked List
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
	int length(ListNode* head) {
		int i = 0;
        ListNode* cur = head;
		while (cur != NULL) {
			i++;
			cur = cur->next;
		}
		return i;
	}
    bool isPalindrome(ListNode* head) {
        int l = length(head);
        if (l < 2) return true;
        int half = (l - 1) / 2;
        int i = 0;
        ListNode* cur = head->next;
        ListNode* pre = head;
        while (i < half) {
        	pre = cur;
        	cur = cur->next;
            i++;
        }
        pre->next = NULL;
        pre = cur;
        cur = cur->next;
        while (cur != NULL) {
            ListNode* tmp = cur;
        	cur = cur->next;
        	tmp->next = pre;
        	pre = tmp;
        }
        cur = head;
        i = 0;
        int j = 0;
        half = l / 2;
        while (i < half) {
        	if (cur->val != pre->val) return false;
        	else {
        		cur = cur->next;
        		pre = pre->next;
                i++;
        	}
        }
        return true;
    }
};