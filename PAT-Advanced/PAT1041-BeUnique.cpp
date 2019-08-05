// PAT1041-BeUnique.cpp
// Ad
// Init: 19Aug05

// Score: 20/20
// Spent Time: 39 min
// Runtime: 65 ms

// -----------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Main ------------------------------------------------------------------------

int main()
{
    int num = 0;
    cin >> num;
    vector<int> numbers;
    map<int, int> counts;
    for (int i = 0; i < num; ++i)
    {
        int input = 0;
        cin >> input;
        counts[input]++;
        numbers.push_back(input);
    }

    bool hasWinner = false;
    for (int number : numbers)
        if (counts[number] == 1)
        {
            hasWinner = true;
            cout << number << endl;
            break;
        }
    if (hasWinner == false)
        cout << "None" << endl;

    return 0;
} // main()
