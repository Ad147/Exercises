# LeetCode 654. Maximum Binary Tree `M`
# 1sk | 88% | 21'
# A~1o30

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        root = TreeNode()
        self.constructSubtree(root, nums)
        return root

    def constructSubtree(self, node, arr):
        if arr == None:
            return
        elif len(arr) == 1:
            node.val = arr[0]
        else:
            node.val = max(arr)
            idx = arr.index(node.val)
            if idx != 0:
                node.left = TreeNode()
                self.constructSubtree(node.left, arr[:idx])
            if idx != len(arr)-1:
                node.right = TreeNode()
                self.constructSubtree(node.right, arr[idx+1:])
