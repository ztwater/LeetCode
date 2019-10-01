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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        while (fast != NULL) {
            if (fast->next == NULL) {
                slow = slow->next;
                break;
            }
            else {
                fast = fast->next->next;
                if (pre != NULL) {
                    pre = slow;
                    slow = slow->next;
                    pre->next = head;
                    head = pre;
                }
                else {
                    pre = head;
                    slow = slow->next;
                    head->next = NULL;
                }
            }
        }
        while (slow != NULL) {
            if (slow->val != pre->val) return false;
            else {
                slow = slow->next;
                pre = pre->next;
            }
        }
        return true;
    }
};