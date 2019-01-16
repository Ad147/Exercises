// LeetCode905-SortArrayByParity.cs
// Ad147
// Init: 19Jan16

/* -----------------------------------------------------------------------------

905. Sort Array By Parity

Easy

Tag: Array

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

```
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

Note:

1. 1 <= A.length <= 5000
2. 0 <= A[i] <= 5000

----------------------------------------------------------------------------- */

// solution ====================================================================

// Runtime: 300 ms, faster than 96.52% of C# online submissions for Sort Array By Parity.

public class Solution
{
    public int[] SortArrayByParity(int[] A)
    {
        int i = 0, j = A.Length - 1;
        while (i < j)
        {
            while ((A[i] % 2 == 0) && (i < j)) { i++; }
            while ((A[j] % 2 != 0) && (i < j)) { j--; }

            if (i == j) return A;
            else
            {
                var temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }

            i++;
            j--;
        }

        return A;
    }
}
