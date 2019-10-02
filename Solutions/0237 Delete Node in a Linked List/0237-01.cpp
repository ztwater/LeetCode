//0237 Delete Node in a Linked List
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
    void deleteNode(ListNode* node) {
    	ListNode* pre = NULL;
        while (node->next != NULL) {
        	node->val = node->next->val;
        	pre = node;
        	node = node->next;
        }
        pre->next = NULL;
        delete(node);
    }
};