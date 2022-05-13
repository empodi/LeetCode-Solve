"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return root
        
        root.next = None
        nodes = [root]
        cnt = 1
        
        while cnt:
            
            nextCnt = 0
            
            for idx in range(cnt):
                
                node = nodes[0]
                nodes.pop(0)
                
                if node.left:
                    if nextCnt:
                        nodes[-1].next = node.left
                    nodes += [node.left]
                    nextCnt += 1
                    
                if node.right:
                    if nextCnt:
                        nodes[-1].next = node.right
                    nodes += [node.right]
                    nextCnt += 1
            
            cnt = nextCnt
        
        return root
                
            
            
            
            
            
            
        
        
            
            
        
        
        
        