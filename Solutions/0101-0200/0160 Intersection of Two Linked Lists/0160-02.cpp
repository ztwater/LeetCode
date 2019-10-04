//160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int more = len(headA) - len(headB);
        while (more > 0) {
            headA = headA->next;
            more--;
        }
        while (more < 0) {
            headB = headB->next;
            more++;
        }
        while (headA != NULL && headB != NULL) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    int len(ListNode* head) {
        int i = 0;
        while (head != NULL) {
            head = head->next;
            i++;
        }
        return i;
    }
};
