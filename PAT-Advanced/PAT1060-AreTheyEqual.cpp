// PAT1060-AreTheyEqual.cpp
// Ad
// Init: 19Aug29

// Score: 19/25
// Time: 60'
// Runtime: 5 ms

#include <iostream>
#include <string>

using namespace std;

string format(const string &n, int numDigits);

// Main ------------------------------------------------------------------------

int main()
{
    int numDigits = 0;
    cin >> numDigits;
    string n1, n2;
    cin >> n1 >> n2;

    string std1 = format(n1, numDigits), std2 = format(n2, numDigits);
    if (std1 == std2)
        cout << "YES " << std1 << endl;
    else
        cout << "NO " << std1 << ' ' << std2 << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

string format(const string &n, int numDigits)
{
    if (n.empty())
        throw exception();

    string ret = "0.";

    bool hasPoint = n.find('.') < n.size();
    int exponent = hasPoint ? n.find('.') : n.size();

    if (numDigits <= exponent)
        ret += n.substr(0, numDigits);
    else if (!hasPoint)
        ret += n + string(numDigits - exponent, '0');
    else
    {
        string noPoint = n.substr(0, exponent) + n.substr(exponent + 1);
        if (numDigits <= noPoint.size())
            ret += noPoint.substr(0, numDigits);
        else
            ret += noPoint + string(numDigits - noPoint.size(), '0');
    }

    ret += "*10^" + to_string(exponent);

    return ret;
}
