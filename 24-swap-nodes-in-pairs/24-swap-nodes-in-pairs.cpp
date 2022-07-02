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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *a = head, *b, *c, *prev = nullptr;
        head = a->next;
        while (true) {
            b = a->next;
            c = b->next;
            if (prev) prev->next = b;
            a->next = b->next;
            b->next = a;
            if (!c || !c->next) break;
            prev = a;
            a = c;
        }
        if (c) a->next = c;
        return head;
    }
};