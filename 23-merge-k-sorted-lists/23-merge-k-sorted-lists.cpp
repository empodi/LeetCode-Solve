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
    struct cmp {
      bool operator() (ListNode* a, ListNode* b) {
          return a->val > b->val;
      }  
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq; 
        ListNode* head = nullptr, *trail;
        
        for (ListNode* node : lists) {
            
            while (node) {
                pq.push(node);
                node = node->next;
            }
        }
        
        if (pq.empty()) return nullptr;
        
        head = pq.top();
        head->next = nullptr;
        trail = head;
        pq.pop();
        
        while (!pq.empty()) {
            
            ListNode* tmp = pq.top();
            pq.pop();
            tmp->next = nullptr;
            trail->next = tmp;
            trail = trail->next;
        }
        
        return head;
    }
};