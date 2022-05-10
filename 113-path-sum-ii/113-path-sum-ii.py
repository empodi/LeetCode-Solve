# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        
        def DFS(node, cur_array, remainingSum):
            
            if node is None: return
            
            remainingSum -= node.val
            
            if remainingSum == 0 and not (node.left or node.right):
                cur_array += [node.val]
                answer.append(cur_array)
                return
            
            DFS(node.left, cur_array + [node.val], remainingSum)
            DFS(node.right, cur_array + [node.val], remainingSum)
            
            #curArray.pop()
            
        answer = []
        DFS(root, cur_array = [], remainingSum = targetSum)
        
        return answer