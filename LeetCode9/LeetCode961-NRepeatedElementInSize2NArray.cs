// LeetCode961-NRepeatedElementInSize2NArray.cs
// Ad147 @Github
// Init: 19Jan23

/* -----------------------------------------------------------------------------

961. N-Repeated Element in Size 2N Array
Easy
Hash Table

In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

Example 1:
----------------------------------------
Input: [1,2,3,3]
Output: 3
----------------------------------------

Example 2:
----------------------------------------
Input: [2,1,2,5,3,2]
Output: 2
----------------------------------------

Example 3:
----------------------------------------
Input: [5,1,5,2,5,3,5,4]
Output: 5
----------------------------------------

Note:
1. 4 <= A.length <= 10000
2. 0 <= A[i] < 10000
3. A.length is even

----------------------------------------------------------------------------- */


// Solution-1 ==================================================================

// Runtime: 148 ms, faster than 100.00% of C# online submissions for N-Repeated Element in Size 2N Array.
// Algorithm: Compare
// TimeComplexity: O(n)
// SpaceComplexity: O(1)

// If we ever find a repeated element, it must be the answer. Let's call this answer the major element.
// Consider all subarrays of length 4. There must be a major element in at least one such subarray.
// This is because either:
// - There is a major element in a length 2 subarray, or;
// - Every length 2 subarray has exactly 1 major element, which means that a length 4 subarray that begins at a major element will have 2 major elements.
// Thus, we only have to compare elements with their neighbors that are distance 1, 2, or 3 away.

public class Solution
{
    public int RepeatedNTimes(int[] A)
    {
        for (int k = 1; k <= 3; k++)
        {
            for (int i = 0; i < A.Length - k; i++)
            {
                if (A[i] == A[i + k]) { return A[i]; }
            }
        }
        return -1;
    }
}


// Solution-0 ==================================================================

// Runtime: 152 ms, faster than 75.47% of C# online submissions for N-Repeated Element in Size 2N Array.
// Algorithm: Traversal, HashTable
// TimeComplexity: O(n) (read array, build and search hash table)
// SpaceComplexity: O(n) (hash table)

public class Solution
{
    public int RepeatedNTimes(int[] A)
    {
        var hs = new HashSet<int>();
        foreach (int i in A)
        {
            if (hs.Contains(i)) { return i; }

            hs.Add(i);
        }
        return -1;
    }
}
