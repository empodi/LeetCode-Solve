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
        ListNode* a = headA;
        ListNode* b = headB;
        ListNode* r = nullptr;
        
        while (a) {
            a->val = -(a->val);
            a = a->next;
        }
        
        while (b) {
            if (b->val < 0) {
                r = b;
                break;
            }
            b = b->next;
        }
        
        a = headA;
        while (a && a->val < 0) {
            a->val = -(a->val);
            a = a->next;
        }
        
        return r;
    }
};