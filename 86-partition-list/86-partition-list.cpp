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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        
        auto dummy = new ListNode();
        auto d_tmp = dummy;
        auto tmp = head;
        ListNode* prev = nullptr;
        
        while (tmp) 
        {
            if (tmp->val >= x) 
            {   
                d_tmp->next = tmp;
                d_tmp = d_tmp->next;
                if (prev) 
                {
                    prev->next = tmp->next; 
                    tmp = tmp->next; 
                }
                else head = tmp = tmp->next;
                d_tmp->next = nullptr;
            }
            else 
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        
        if (prev)
            prev->next = dummy->next;
        if (!head)
            head = dummy->next;
        delete dummy;
        return head;
    }
};