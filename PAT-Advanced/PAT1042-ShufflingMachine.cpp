// PAT1042-ShufflingMachine.cpp
// Ad
// Init: 19Aug08

// Score: 20/20
// Time: 58 min
// Runtime: 3 ms

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> shuffle(const vector<string> &cards, const vector<int> &shuffleOrder, int shuffleTime);

// Main ------------------------------------------------------------------------

int main()
{
    int shuffleTime = 0;
    cin >> shuffleTime;
    vector<int> shuffleOrder;
    for (int i = 0; i < 54; ++i)
    {
        int num = 0;
        cin >> num;
        shuffleOrder.push_back(num);
    }
    vector<string> cards = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};

    vector<string> shuffleResult = shuffle(cards, shuffleOrder, shuffleTime);

    cout << shuffleResult[0];
    for (int i = 1; i < 54; ++i)
        cout << ' ' << shuffleResult[i];

    return 0;
}

// Functions -------------------------------------------------------------------

vector<string> shuffle(const vector<string> &cards, const vector<int> &shuffleOrder, int shuffleTime)
{
    vector<vector<string>> result{cards, cards};

    for (int i = 0; i < shuffleTime; ++i)
        for (int j = 0; j < 54; ++j)
            result[(i + 1) % 2][shuffleOrder[j] - 1] = result[i % 2][j];

    return result[shuffleTime % 2];
}
