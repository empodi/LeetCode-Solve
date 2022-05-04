# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head: return None
        
        check = [False for i in range(201)]
        
        check[head.val + 100] = True
        
        prev = head
        cur = head.next
        
        while cur:
            
            curVal = cur.val + 100
            
            if check[curVal]:
                if not cur.next:
                    prev.next = None
                    break
                else:
                    prev.next = cur.next
                    cur = cur.next
            else:
                check[curVal] = True
                cur = cur.next
                prev = prev.next
            
        return head
                    
                    
                    
            
            
        
        
        
        
        