# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        answer = []
        
        if not root: return []
        
        nodes = [root]
        
        while nodes:
            
            values = []

            nodeLen = len(nodes)
            
            for i in range(nodeLen):
                
                values.append(nodes[0].val)
                
                if nodes[0].left:
                    nodes.append(nodes[0].left)
                if nodes[0].right:
                    nodes.append(nodes[0].right)
                
                nodes.pop(0)
            
            answer.insert(0, values)
                
        
        return answer
        