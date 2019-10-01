//206. Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* cur = head->next;
        ListNode* tail = head;
        while (cur != NULL) {
        	head->next = cur->next;
        	cur->next = tail;
        	tail = cur;
        	cur = head->next;
        }
        return tail;
    }
};