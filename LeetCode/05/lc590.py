# lc590.py

# LeetCode 590. N-ary Tree Postorder Traversal `E`
# 1sk | 23% | 4'
# A~0g05

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    res = []

    def postorder(self, root: "Node") -> List[int]:
        self.res = []
        self.traverse(root)

        return self.res

    def traverse(self, node):
        if not node:
            return

        for c in node.children:
            self.traverse(c)
        self.res.append(node.val)
