// LeetCode965-UnivaluedBinaryTree.cs
// Ad147
// Init: 19Jan10

/* -----------------------------------------------------------------------------

A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

Example 1:

      (1)
     /   \
  (1)     (1)
  / \       \
(1) (1)     (1)

```
Input: [1,1,1,1,1,null,1]
Output: true
```

Example 2:

     (2)
    /   \
  (2)   (2)
 /   \
(5) (2)

```
Input: [2,2,2,5,2]
Output: false
```

Note:

- The number of nodes in the given tree will be in the range [1, 100].
- Each node's value will be an integer in the range [0, 99].

----------------------------------------------------------------------------- */

// Definition for a binary tree node.
public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

// solution ====================================================================

// Runtime: 116 ms, faster than 39.13%

public class Solution
{
    public bool IsUnivalTree(TreeNode root)
    {
        bool left_ret = true;
        bool right_ret = true;

        if ((root.left == null) && (root.right == null))
            return true;

        if (root.left != null)
            if (root.left.val != root.val)
                return false;
            else
                left_ret = IsUnivalTree(root.left);

        if (root.right != null)
            if (root.right.val != root.val)
                return false;
            else
                right_ret = IsUnivalTree(root.right);

        return left_ret && right_ret;
    }
}
