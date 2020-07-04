# lc589.py

# LeetCode 589. N-ary Tree Preorder Traversal `E`
# acc | 22%* | 11'
# A~0g04

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    res = []

    def preorder(self, root: "Node") -> List[int]:
        self.res = []
        self.traverse(root)

        return self.res

    def traverse(self, node: "Node"):
        if not node:
            return

        self.res.append(node.val)
        for c in node.children:
            self.traverse(c)
