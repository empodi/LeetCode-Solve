/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        int carry = 0;
        ListNode *prev, *ret = a;
        while (a && b) {
            a->val += (b->val + carry);
            carry = a->val / 10;
            a-> val %= 10;
            prev = a;
            a = a->next;
            b = b->next;
        }
        ListNode *trav = a ? a : b;
        prev->next = trav;
        
        while (trav) {
            trav->val += carry;
            carry = trav->val / 10;
            trav->val %= 10;
            prev = trav;
            trav = trav->next;
        }
        if (carry) {
            ListNode* tmp = new ListNode(1);
            prev->next = tmp;
        }
        
        return ret;
    }
};