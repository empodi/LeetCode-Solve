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
        
        unordered_set<ListNode*> u;
        
        while (a) {
            u.insert(a);
            a = a->next;
        }
        
        while (b) {
            auto it = u.find(b);
            if (it != u.end()) 
                return b;
            b = b->next;
        }
        
        return nullptr;
    }
};