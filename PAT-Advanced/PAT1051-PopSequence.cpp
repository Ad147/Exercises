// PAT1051-PopSequence.cpp
// Ad
// Init: 19Aug20

// Score: 25/25
// Time: 58'
// Runtime: 5 ms

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string checkPopSeq(const vector<int> &seq, int stackCapa);

// Main ------------------------------------------------------------------------

int main()
{
    int stackCapa = 0, seqLen = 0, numSeqs = 0;
    cin >> stackCapa >> seqLen >> numSeqs;
    vector<vector<int>> sequences(numSeqs);
    for (int i = 0; i < numSeqs; ++i)
        for (int j = 0; j < seqLen; ++j)
        {
            int n = 0;
            cin >> n;
            sequences[i].push_back(n);
        }

    for (auto seq : sequences)
        cout << checkPopSeq(seq, stackCapa) << endl;

    system("pause");
    return 0;
}

// Function --------------------------------------------------------------------

string checkPopSeq(const vector<int> &seq, int stackCapa)
{
    vector<int> stack;
    for (int i = 0, n = 1; i < seq.size();)
    {
        while (stack.empty() || stack.back() != seq[i])
        {
            if (stack.size() >= stackCapa || n > seq.size())
                return "NO";

            stack.push_back(n++);
        }

        while (!stack.empty() && stack.back() == seq[i])
        {
            stack.pop_back();
            ++i;
        }
    }

    return "YES";
}
