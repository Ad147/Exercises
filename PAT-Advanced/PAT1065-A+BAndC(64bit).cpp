// PAT1065-A+BAndC(64bit).cpp
// Ad
// Init: 19Sep03

// Score: 16/20
// Time: 45'
// Runtime: 3 ms

#include <iostream>
#include <vector>

using namespace std;

bool judge(long long a, long long b, long long c);

// Class --------------------------------------------------------

struct Group
{
    long long a;
    long long b;
    long long c;
};

// Main ---------------------------------------------------------

int main()
{
    int numCases = 0;
    cin >> numCases;
    vector<Group> cases;
    for (int i = 0; i < numCases; ++i)
    {
        long long a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        cases.push_back({a, b, c});
    }

    for (int i = 0; i < numCases; ++i)
        cout << "Case #" << i + 1 << ": " << (judge(cases[i].a, cases[i].b, cases[i].c) ? "true" : "false") << endl;
    
    return 0;
}

// Function -------------------------------------------------------------------

bool judge(long long a, long long b, long long c)
{
    if ((a >= 0 && b <= 0) || (a <=0 && b >= 0))
        return a + b > c;

    unsigned long long sum = a + b, uc = c;

    if (a > 0 && c <= 0)
        return true;
    else if (a < 0 && c >= 0)
        return false;
    else if (a > 0 && c > 0)
        return sum > uc;
    else
        return sum < uc;
}

