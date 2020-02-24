// LC744-FindSmallestLetterGreaterThanTarget.cpp
// Ad
// Init: 19Sep22

// Difficulty: Easy
// Status: OSK
// Time: 20'
// Runtime: 99%
// Memory: 72%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0, right = letters.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target < letters[mid])
            {
                if (mid == 0 || letters[mid - 1] <= target)
                    return letters[mid];
                else
                    right = mid - 1;
            }
            else
            {
                if (mid == letters.size() - 1)
                    return letters.front();
                else
                    left = mid + 1;
            }
        }

        return 'A';
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<char> letters{'c', 'f', 'j'};
    vector<char> targets{'a', 'c', 'd', 'g', 'j', 'k'};

    for (auto c : targets)
        cout << sol.nextGreatestLetter(letters, c) << endl;

    system("pause");
    return 0;
}