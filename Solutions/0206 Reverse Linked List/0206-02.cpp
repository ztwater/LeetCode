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
        stack<ListNode*> s;
        ListNode* cur = head;
        while (cur != NULL) {
            s.push(cur);
            cur = cur->next;
        }
        head = s.top();
        cur = head;
        s.pop();
        while (!s.empty()) {
            cur->next = s.top();
            cur = cur->next;
            s.pop();
        }
        cur->next = NULL;
        return head;
    }
};
