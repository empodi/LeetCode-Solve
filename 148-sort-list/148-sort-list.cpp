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
    ListNode* sortList(ListNode* head) {
        
        if (!head) return nullptr;
        
        vector<int> v;
        
        ListNode* tmp = head;
        
        while (tmp) {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        sort(v.begin(), v.end());
        
        ListNode* node = new ListNode(v[0]);
        tmp = node;
        
        for (int i = 1; i < v.size(); i++) {
            
            ListNode* newNode = new ListNode(v[i]);
            
            node->next = newNode;
            node = node->next;
        }
        
        return tmp;
    }
};