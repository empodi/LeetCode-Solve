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
        
        if (!head || !head->next) return head;
        
        ListNode* first, *mid, *back, *node, *firstTrail, *midTrail;
        
        first = firstTrail = new ListNode();
        mid = midTrail = new ListNode();
        
        node = head;
        
        while (1) {
            back = node->next;
            
            if (node->val < x) {
                node->next = nullptr;
                firstTrail->next = node;
                firstTrail = firstTrail->next;
            }
            else {
                node->next = nullptr;
                midTrail->next = node;
                midTrail = midTrail->next;
            }
            
            if (!back) break;
            node = back;
        }
        
        if (first->next) {
            firstTrail->next = mid->next;
            return first->next;
        }
        else return mid->next;
    }
};