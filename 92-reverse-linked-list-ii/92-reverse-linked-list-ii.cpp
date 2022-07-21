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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (!head || !(head->next) || left == right) return head;
        
        ListNode* s = nullptr, *cur = head, *tempCur, *back, *last;
        
        for (int i = 0; i < left - 1; i++) {
            s = cur;
            cur = cur->next;
        }
        tempCur = cur;
        back = cur->next;
        
        for (int i = 0; i < right - left; i++) {
            
            last = back->next;
            back->next = cur;
            cur = back;
            back = last;
        }

        tempCur->next = back;
        
        if (s) {
            s->next = cur;
            return head;
        }
        else return cur;
    }
};