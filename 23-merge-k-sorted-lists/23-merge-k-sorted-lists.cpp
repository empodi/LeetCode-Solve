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
    int listLen = 0;
    vector<vector<ListNode*>> v{20002};
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        listLen = lists.size();
        ListNode* head = nullptr, *prev;
        
        if (!listLen) return nullptr;
        
        for (int i = 0; i < listLen; i++) {
        
            ListNode* node = lists[i];
            
            while(node) {
                v[node->val + 10000].push_back(node);
                node = node->next;
            }
        }
        
        for (int i = 0; i < 20002; i++) {
            
            for (int j = 0; j < v[i].size(); j++) {
                
                if (!head) {
                    head = v[i][j];
                    head->next = nullptr;
                    prev = head;
            
                }
                else {
                    prev->next = v[i][j];
                    prev = v[i][j];
                }
            }
        }
        
        return head;
    }
};