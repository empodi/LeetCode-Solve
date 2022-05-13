# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        return self.solve(root) != -1
 
    def solve(self, node: Optional[TreeNode]) -> int:
        
        if not node:
            return 0
        
        if not (node.left or node.right):
            return 1
        
        lv, rv = self.solve(node.left), self.solve(node.right)
        
        if lv < 0 or rv < 0 or abs(lv - rv) > 1:
            return -1
        
        return max(lv, rv) + 1