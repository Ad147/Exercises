// LeetCode942-DIStringMatch.cs
// Ad147 @Github
// Init: 19Feb03

/* -----------------------------------------------------------------------------

942. DI String Match
Easy
Match

Given a string S that **only** contains "I" (increase) or "D" (decrease), let N = S.length.

Return **any** permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

- If S[i] == "I", then A[i] < A[i+1]
- If S[i] == "D", then A[i] > A[i+1]

Example 1:
----------------------------------------
Input: "IDID"
Output: [0,4,1,3,2]
----------------------------------------

Example 2:
----------------------------------------
Input: "III"
Output: [0,1,2,3]
----------------------------------------

Example 3:
----------------------------------------
Input: "DDI"
Output: [3,2,0,1]
----------------------------------------

Note:

1. 1 <= S.length <= 10000
2. S only contains characters "I" or "D".

----------------------------------------------------------------------------- */


// Solution-0 ==================================================================

// Runtime: 288 ms, faster than 100.00% of C# online submissions for DI String Match.
// Memory Usage: 20.2 MB, less than 100.00% of C# online submissions for DI String Match.

/* -----------------------------------------------------------------------------

Approach: Ad-Hoc

Intuition
If we see say S[0] == 'I', we can always put 0 as the first element;  
similarly, if we see S[0] == 'D', we can always put N as the first element.

Say we have a match for the rest of the string S[1], S[2], ... using N distinct elements.  
Notice it doesn't matter what the elements are, only that they are distinct and totally ordered.  
Then, putting 0 or N at the first character will match, and the rest of the elements (1, 2, ..., N or 0, 1, ..., N-1) can use the matching we have.

Algorithm
Keep track of the smallest and largest element we haven't placed. If we see an 'I', place the small element; otherwise place the large element.

Time Complexity: O(n).
Space Complexity: O(n).

----------------------------------------------------------------------------- */

public class Solution
{
    public int[] DiStringMatch(string S)
    {
        var ret = new int[S.Length + 1];
        int min = 0, max = S.Length;
        for (int i = 0; i < S.Length; i++)
        {
            if (S[i] == 'I') { ret[i] = min++; }
            else { ret[i] = max--; }
        }
        ret[S.Length] = min;
        return ret;
    }
}
