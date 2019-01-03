// LeetCode507-PerfectNumber.cs
// Ad147
// Init: 19Jan03

/* -----------------------------------------------------------------------------

We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)

----------------------------------------------------------------------------- */

// solution #1 -----------------------------------------------------------------

// Approach #1 Brute Force [Time Limit Exceeded]

public class Solution
{
    public bool CheckPerfectNumber(int num)
    {
        if (num < 6)
            return false;

        int sum = 0;
        for (int i = 2; i * 2 <= num; ++i)
            if (num % i == 0)
                sum += i;

        return (sum + 1 == num);
    }
}

// solution #2 -----------------------------------------------------------------

// Runtime: 44 ms, faster than 97.30% of C# online submissions for Perfect Number.
// Only iterate up to sqrt(num) to get factors.

public class Solution
{
    public bool CheckPerfectNumber(int num)
    {
        if (num < 6)
            return false;

        int sum = 1, i = 0;
        for (i = 2; i * i < num; ++i)
            if (num % i == 0)
                sum += (i + num / i);
        
        if (i * i == num)
            num += i;
        
        return sum == num;
    }
}
