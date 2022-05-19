# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDepth(self, node: TreeNode) -> int:
        
        if not (node.left or node.right): return 0
        
        ldepth =  self.findDepth(node.left) if node.left else 0
        rdepth = self.findDepth(node.right) if node.right else 0
        return 1 + max(ldepth, rdepth)
    
    def findSubtree(self, node: TreeNode, curDepth: int, targetDepth: int) -> TreeNode:
        
        if curDepth == targetDepth or not node: return node
        #if not (node.left or node.right): return None
        
        lnode = self.findSubtree(node.left, curDepth + 1, targetDepth)
        rnode = self.findSubtree(node.right, curDepth + 1, targetDepth)
        
        if lnode and rnode: return node
        elif lnode: return lnode
        else: return rnode
        
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        
        depth = self.findDepth(root)
        
        if not depth: return root

        return self.findSubtree(root, 0, depth)
            
            