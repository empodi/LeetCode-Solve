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
    int listLen;
    ListNode* nodeArray[25010];
    
    int getLen(ListNode* head) {
        
        ListNode* tmp = head;
        int cnt = 0;
        
        while (tmp) {
            cnt++;
            tmp = tmp->next;
        }
        
        return cnt;
    }
    
    void reorderList(ListNode* head) {
        
        listLen = getLen(head);
        int halfLen = (listLen - 1) / 2;
        
        if (listLen < 3) return;
        
        ListNode* node = head;
        
        for (int i = 0; i < listLen; i++) {
            
            if (i <= halfLen) {
                nodeArray[i] = node;
                node = node->next;
                nodeArray[i]->next = nullptr;
            }
            else {
                nodeArray[listLen - i - 1]->next = node;
                node = node->next;
                nodeArray[listLen - i - 1]->next->next = nullptr;
            }
        }
        
        head = nodeArray[0];
        ListNode* trail = head->next;
        
        for (int i = 1; i <= halfLen; i++) {
            trail->next = nodeArray[i];
            trail = nodeArray[i]->next;
        }
        
    }
};