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

        # q = deque([root, None])
        # s = cnt = 0
        # while q:
        #     n = q.popleft()
        #     if not n:
        #         if cnt == 0:
        #             break
        #         res.append(s/cnt)
        #         q.append(None)
        #         s = cnt = 0
        #     else:
        #         s += n.val
        #         cnt += 1
        #         if n.left:
        #             q.append(n.left)
        #         if n.right:
        #             q.append(n.right)

        # return res
