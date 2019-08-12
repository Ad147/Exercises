// LeetCode977-SquaresOfASortedArray.cs
// Ad147 @Github
// Init: 19Jan21

/* -----------------------------------------------------------------------------

977. Squares of a Sorted Array
Easy
Tags: Array, Two Pointers, Sort

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:
----------------------------------------
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
----------------------------------------

Example 2:
----------------------------------------
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
----------------------------------------

Note:
1. 1 <= A.length <= 10000
2. -10000 <= A[i] <= 10000
3. A is sorted in non-decreasing order.

----------------------------------------------------------------------------- */

// Solution ====================================================================

// Runtime: 352 ms, faster than 100.00% of C# online submissions for Squares of a Sorted Array.
// Algorithm: Two Pointers Traversal
// TimeComplexity: O(n)
// SpaceComplexity: O(1)

public class Solution
{
    public int[] SortedSquares(int[] A)
    {
        int[] ret = new int[A.Length];
        int left = 0, right = A.Length - 1;
        for (int i = ret.Length - 1; i >= 0; i--)
        {
            int n1 = A[left] * A[left];
            int n2 = A[right] * A[right];
            if (n1 > n2)
            {
                ret[i] = n1;
                left++;
            }
            else
            {
                ret[i] = n2;
                right--;
            }
        }

        return ret;
    }
}
