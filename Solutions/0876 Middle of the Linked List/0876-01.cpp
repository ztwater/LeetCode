//0876 Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
    	if (head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
        	if (fast->next == NULL) {
        		return slow;
        	}
        	fast = fast->next->next;
        	slow = slow->next;
        }
        return slow;
    }
};