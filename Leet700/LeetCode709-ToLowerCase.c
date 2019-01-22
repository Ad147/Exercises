// LeetCode709-ToLowerCase.c
// Ad147 @Github
// Init: 19Jan22

/* -----------------------------------------------------------------------------

709. To Lower Case
Easy
Tag: string

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:
----------------------------------------
Input: "Hello"
Output: "hello"
----------------------------------------

Example 2:
----------------------------------------
Input: "here"
Output: "here"
----------------------------------------

Example 3:
----------------------------------------
Input: "LOVELY"
Output: "lovely"
----------------------------------------

----------------------------------------------------------------------------- */

// Solution ====================================================================

// Runtime: 0 ms, faster than 100.00% of C online submissions for To Lower Case.
// Algorithm: Traversal.
// TimeComplexity: O(n).
// SpaceComplexity: O(1).

char *toLowerCase(char *str)
{
    char *p = str;
    while (*p != '\0')
    {
        if (65 <= *p && *p <= 90)
        {
            *p += 32;
        }
        ++p;
    }
    return str;
}
