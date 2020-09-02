# LeetCode 872. Leaf-Similar Trees `E`
# 1sk | 100% | 21'
# A~0v01

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        stk1, stk2 = [root1], [root2]
        while stk1 and stk2:
            val1 = self.get_next_leaf(stk1)
            val2 = self.get_next_leaf(stk2)
            if val1 and val2:
                if val1 != val2:
                    return False
            else:
                return not val1 and not val2
        return not stk1 and not stk2

    def get_next_leaf(self, stk):
        while stk:
            node = stk.pop()
            if not node.left and not node.right:
                return node.val
            else:
                if node.right:
                    stk.append(node.right)
                if node.left:
                    stk.append(node.left)
