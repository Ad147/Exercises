# LeetCode 783. Minimum Distance Between BST Nodes `E`
# acc | 92% | 29'
# A~0h12

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    inorder = []

    def minDiffInBST(self, root: TreeNode) -> int:
        self.inorder.clear()
        self.traversal(root)
        return min(self.inorder[i+1] - self.inorder[i] for i in range(len(self.inorder)-1))

    def traversal(self, root):
        if not root:
            return
        self.traversal(root.left)
        self.inorder.append(root.val)
        self.traversal(root.right)
