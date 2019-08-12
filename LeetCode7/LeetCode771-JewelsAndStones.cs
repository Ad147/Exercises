// LeetCode771-JewelsAndStones.cs
// Ad147 @Github
// Init: 19Jan18

/* -----------------------------------------------------------------------------

771. Jewels and Stones

Easy

Tag: HashTable

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
Each character in S is a type of stone you have.  
You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters.  
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

```
Input: J = "aA", S = "aAAbbbb"
Output: 3
```

Example 2:

```
Input: J = "z", S = "ZZ"
Output: 0
```

Note:

- S and J will consist of letters and have length at most 50.
- The characters in J are distinct.

----------------------------------------------------------------------------- */

// Solution-0 ==================================================================

// Runtime: 92 ms, faster than 55.76% of C# online submissions for Jewels and Stones.
// `final`

// Algorithm: Traversal.
// TimeComplexity: O(m+n).
// SpaceComplexity: O(m).

public class Solution
{
    public int NumJewelsInStones(string J, string S)
    {
        if (string.IsNullOrEmpty(J) || string.IsNullOrEmpty(S)) { return 0; }

        var jewels = new HashSet<char>();
        foreach (var ch in J) { jewels.Add(ch); }

        int cnt = 0;
        foreach (var ch in S)
        {
            if (jewels.Contains(ch)) { cnt++; }
        }

        return cnt;
    }
}
