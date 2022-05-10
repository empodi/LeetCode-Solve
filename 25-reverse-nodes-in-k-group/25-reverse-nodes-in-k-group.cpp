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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (!head->next || k == 1)
            return head;
        
        ListNode *node, *prev, *back, *rev;
        
        node = head; 
        prev = nullptr;
        
        while (true) {
            
            rev = node;
            int cnt = 1;
            
            while (rev && cnt != k) {
                rev = rev->next;
                cnt++;
            }
            
            if (!rev) break;
            
            back = rev->next;
            
            if (prev) prev->next = rev;
            else head = rev;
            
            ListNode* tmp = node;
            ListNode* tmpNext = tmp->next;
            ListNode* tmpNextNext = tmpNext->next;
            
            while (true) {       
                tmpNext->next = tmp;
                if (tmpNext == rev) break;
                
                tmp = tmpNext;
                tmpNext = tmpNextNext;
                tmpNextNext = tmpNextNext->next;
            }
            
            node->next = back;
            
            if (!back) break;
            
            prev = node;
            node = back;
        }
        
        return head;
    }
};