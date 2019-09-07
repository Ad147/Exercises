// PAT1067-SortWithSwap(0,i).cpp
// Ad
// Init: 19Sep07

// Score: 19/25
// Time: 60'
// Runtime: 3 ms

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

size_t sortBySwap0(vector<int> &numbers);
bool isSorted(vector<int> &numbers, vector<int>::iterator &next);

// Main ------------------------------------------------------------------

int main()
{
    int numNumbers = 0;
    cin >> numNumbers;
    vector<int> numbers;
    for (int i = 0; i < numNumbers; ++i)
    {
        int n = 0;
        cin >> n;
        numbers.push_back(n);
    }

    cout << sortBySwap0(numbers) << endl;
    
    return 0;
}

// Function --------------------------------------------------------------

size_t sortBySwap0(vector<int> &numbers)
{
    if (numbers.empty())
        return 0;

    size_t cnt = 0;
    auto itr0 = find(numbers.begin(), numbers.end(), 0);
    size_t idx0 = itr0 - numbers.begin();

    for (size_t i = 0; i < numbers.size() * 2; ++i)
    {
        vector<int>::iterator next = numbers.end();
        if (isSorted(numbers, next))
            break;

        if (idx0 != 0)
        {
            auto tmp = find(numbers.begin(), numbers.end(), idx0);
            iter_swap(itr0, tmp);
            itr0 = tmp;
        }
        else
        {
            iter_swap(itr0, next);
            itr0 = next;
        }

        idx0 = itr0 - numbers.begin();
        ++cnt;
    }

    return cnt;
}

bool isSorted(vector<int> &numbers, vector<int>::iterator &next)
{
    for (size_t i = 0; i < numbers.size(); ++i)
        if (numbers[i] != i)
        {
            next = numbers.begin() + i;
            return false;
        }
    
    next = numbers.end();
    return true;
}

