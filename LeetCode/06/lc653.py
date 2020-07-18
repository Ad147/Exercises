# lc653.py

# LeetCode 653. Two Sum IV - Input is a BST `E`
# acc | 98% | 27'
# A~0g18

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        s = set()
        que = [root]
        for i in que:
            if k - i.val in s:
                return True
            s.add(i.val)
            if i.left:
                que.append(i.left)
            if i.right:
                que.append(i.right)

        return False
