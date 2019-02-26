// LeetCode060-PermutationSequence.cpp
// Ad147
// Init: 19Feb26

/* -----------------------------------------------------------------------------

60. Permutation Sequence
Medium
Math, Backtracking

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

Given n and k, return the kth permutation sequence.

Note:

- Given n will be between 1 and 9 inclusive.
- Given k will be between 1 and n! inclusive.

Example 1:
----------------------------------------
Input: n = 3, k = 3
Output: "213"
----------------------------------------

Example 2:
----------------------------------------
Input: n = 4, k = 9
Output: "2314"
----------------------------------------

----------------------------------------------------------------------------- */

#include <vector>
#include <string>

// Solution-0 ==================================================================

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Permutation Sequence.
// Memory Usage: 9.2 MB, less than 92.77% of C++ online submissions for Permutation Sequence.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    std::string getPermutation(int n, int k)
    {
        std::string ret;
        std::vector<int> numbers;
        for (int i = 1; i <= n; ++i)
            numbers.push_back(i);

        int times = n;
        for (int i = 0; i < times; ++i)
        {
            int groupSize = 1;
            for (int j = 2; j < n; ++j)
                groupSize *= j;

            int index = (k % groupSize) ? (k / groupSize) : (k / groupSize - 1);
            ret.push_back(numbers[index] + 48);
            numbers.erase(numbers.begin() + index);

            n--;
            k = k - groupSize * index;
        }

        return ret;
    }
};
