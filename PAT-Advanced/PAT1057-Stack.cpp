// PAT1057-Stack.cpp
// Ad
// Init: 19Aug26

// Score: 17/30
// Time: 60'
// Runtime: 4 ms

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void push(vector<int> &stack);
void pop(vector<int> &stack, vector<string> &output);
void peek(vector<int> stack, vector<string> &output);

// Main ------------------------------------------------------------------------

int main()
{
    int numCommands = 0;
    cin >> numCommands;

    vector<int> stack;
    vector<string> output;
    for (int i = 0; i < numCommands; ++i)
    {
        string command;
        cin >> command;
        if (command == "Push")
            push(stack);
        else if (command == "Pop")
            pop(stack, output);
        else if (command == "PeekMedian")
            peek(stack, output);
        else
            throw exception();
    }

    for (auto o : output)
        cout << o << endl;

    system("pause");
    return 0;
}

// Functions ---------------------------------------------------------------

void push(vector<int> &stack)
{
    int key = 0;
    cin >> key;
    stack.push_back(key);
}

void pop(vector<int> &stack, vector<string> &output)
{
    if (stack.empty())
    {
        output.push_back("Invalid");
        return;
    }

    output.push_back(to_string(stack.back()));
    stack.pop_back();
}

void peek(vector<int> stack, vector<string> &output)
{
    if (stack.empty())
    {
        output.push_back("Invalid");
        return;
    }

    int mid = (stack.size() % 2 == 0) ? stack.size() / 2 : (stack.size() + 1) / 2;
    nth_element(stack.begin(), stack.begin() + mid - 1, stack.end());
    output.push_back(to_string(stack[mid - 1]));
}
