# lc637.py

# LeetCode 637. Average of Levels in Binary Tree `E`
# acc | 35%* | 35'
# A~0g15

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        res = []
        lvl = [root]
        while lvl:
            res.append(sum([i.val for i in lvl])/len(lvl))
            tmp = []
            while lvl:
                n = lvl.pop()
                if n.left:
                    tmp.append(n.left)
                if n.right:
                    tmp.append(n.right)
            lvl = tmp

        return res
