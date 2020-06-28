# lc559.py

# LeetCode 559. Maximum Depth of N-ary Tree `E`
# 1sk | 80% | 21'
# A~0f28

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: "Node") -> int:
        if not root:
            return 0

        maxDepthVal = 0
        for node in root.children:
            depth = self.maxDepth(node)
            if depth > maxDepthVal:
                maxDepthVal = depth

        return maxDepthVal + 1
