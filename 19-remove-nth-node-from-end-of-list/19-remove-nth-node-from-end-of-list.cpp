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
        ListNode *slow = nullptr, *fast = head;
        
        while (fast) {
            if (n-- <= 0) 
                slow = slow ? slow->next : head;
            fast = fast->next;
        }
        // slow points to the prev of target to delete

        if (!slow) return head->next;
        slow->next = slow->next->next;
        return head;
    }
};