// LeetCode412-FizzBuzz.cs
// Ad147
// Init: 19Jan04

/* -----------------------------------------------------------------------------

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

```
n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
```

----------------------------------------------------------------------------- */

// solution #1 -----------------------------------------------------------------

// Runtime: 312 ms, faster than 42.01% of C# online submissions for Fizz Buzz.

public class Solution
{
    public IList<string> FizzBuzz(int n)
    {
        List<string> ret = new List<string>();
        if (n < 1)
            return ret;

        for (int i = 1; i <= n; ++i)
        {
            if (i % 15 == 0)
                ret.Add("FizzBuzz");
            else if (i % 3 == 0)
                ret.Add("Fizz");
            else if (i % 5 == 0)
                ret.Add("Buzz");
            else
                ret.Add(i.ToString());
        }
        return ret;
    }
}

// solution #2 -----------------------------------------------------------------

// Runtime: 288 ms, faster than 99.73% of C# online submissions for Fizz Buzz.

public class Solution
{
    public IList<string> FizzBuzz(int n)
    {
        var ret = new List<string>();
        for (int i = 1; i <= n; ++i)
        {
            if (i % 15 == 0)
                ret.Add("FizzBuzz");
            else
            {
                if (i % 5 == 0)
                    ret.Add("Buzz");
                else
                {
                    if (i % 3 == 0)
                        ret.Add("Fizz");
                    else
                        ret.Add(i.ToString());
                }
            }
        }
        return ret;
    }
}
