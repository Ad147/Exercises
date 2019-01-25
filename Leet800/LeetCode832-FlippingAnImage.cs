// LeetCode832-FlippingAnImage.cs
// Ad147 @Github
// Init: 19Jan25

/* -----------------------------------------------------------------------------

832. Flipping an Image
Easy
Array

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  
For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.  
For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:
----------------------------------------
Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
----------------------------------------

Example 2:
----------------------------------------
Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
----------------------------------------

Notes:
- 1 <= A.length = A[0].length <= 20
- 0 <= A[i][j] <= 1

----------------------------------------------------------------------------- */


// Solution-0 ==================================================================

// Runtime: 296 ms, faster than 68.47% of C# online submissions for Flipping an Image.
// `final`
// Algorithm: Traversal
// TimeComplexity: O(n^2)
// SpaceComplexity: O(1)

public class Solution
{
    public int[][] FlipAndInvertImage(int[][] A)
    {
        foreach (int[] row in A)
        {
            for (int beg = 0, end = row.Length - 1; beg < (row.Length + 1) / 2; beg++, end--)
            {
                int temp = row[beg];
                row[beg] = 1 - row[end];
                row[end] = 1 - temp;
            }
        }
        return A;
    }
}
