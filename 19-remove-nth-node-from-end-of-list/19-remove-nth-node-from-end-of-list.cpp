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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;
        
        int len = 0;
        ListNode* tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        
        if (len == n) return head->next;
        
        tmp = head;
        int target = len - n - 1;
        while (target-- > 0) {
            tmp = tmp->next;
        }
        
        if (tmp->next->next == nullptr) 
            tmp->next = nullptr;
        else 
            tmp->next = tmp->next->next;
        
        return head;
    }
};