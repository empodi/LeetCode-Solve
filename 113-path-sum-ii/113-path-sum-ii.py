# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        
        answer = []
        
        def DFS(node, currentSum, curArray):
            
            if node is None: return
            
            curArray.append(node.val)
            currentSum += node.val
            
            if node.left is None and node.right is None: # leaf node
                if currentSum == targetSum:
                    answer.append(curArray.copy())
            
            DFS(node.left, currentSum, curArray)
            DFS(node.right, currentSum, curArray)
            
            curArray.pop()
            
        DFS(root, 0, [])
        
        return answer