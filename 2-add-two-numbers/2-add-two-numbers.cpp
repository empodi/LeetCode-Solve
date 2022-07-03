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
        ListNode *ret = a, *prev = nullptr;
        int carry = 0;
        
        while (a && b) {
            a->val += (b->val + carry);
            carry = a->val / 10;
            a->val %= 10;
            prev = a;
            a = a->next;
            b = b->next;
        }
        prev->next = a ? a : b;
        while (a) {
            a->val += carry;
            carry = a->val / 10;
            a->val %= 10;
            prev = a;
            a = a->next;
        }
        while (b) {
            b->val += carry;
            carry = b->val / 10;
            b->val %= 10;
            prev = b;
            b = b->next;
        }
        if (carry) {
            ListNode *last = new ListNode(1);
            prev->next = last;
        }
        return ret;
    }
};