// PAT1035-Password.cpp
// Ad
// Init: 19May29

// Score: 20/20 (One-Shot Kill)
// Spent time: 25 min
// Runtime: 5 ms

/* -----------------------------------------------------------------------------

1035 Password (20 分)

To prepare for PAT, the judge sometimes has to generate random passwords for the users. 
The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). 
One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. 
Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.

### Input Specification:

Each input file contains one test case. 
Each case contains a positive integer N (≤1000), followed by N lines of accounts. 
Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.

### Output Specification:

For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. 
The accounts must be printed in the same order as they are read in. 
If no account is modified, print in one line There are N accounts and no account is modified where N is the total number of accounts. 
However, if N is one, you must print There is 1 account and no account is modified instead.

----------------------------------------
Sample Input 1:
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa
Sample Input 2:
1
team110 abcdefg332
Sample Output 2:
There is 1 account and no account is modified
Sample Input 3:
2
team110 abcdefg222
team220 abcdefg333
Sample Output 3:
There are 2 accounts and no account is modified
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<string, string>> modifyAccounts(int numAccounts);
void printModification(vector<pair<string, string>>, int numAccounts);

// Main ------------------------------------------------------------------------

int main()
{
    int numAccounts = 0;
    cin >> numAccounts;

    auto modified = modifyAccounts(numAccounts);

    printModification(modified, numAccounts);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<pair<string, string>> modifyAccounts(int numAccounts)
{
    vector<pair<string, string>> modified;

    for (int i = 0; i < numAccounts; ++i)
    {
        string username, password;
        cin >> username >> password;
        string originalPassword = password;

        for (int j = 0; j < password.size(); ++j)
        {
            switch (password[j])
            {
            case '1':
                password[j] = '@';
                break;
            case '0':
                password[j] = '%';
                break;
            case 'l':
                password[j] = 'L';
                break;
            case 'O':
                password[j] = 'o';
                break;
            default:
                break;
            }
        }
        if (password != originalPassword)
            modified.push_back({username, password});
    }

    return modified;
}

void printModification(vector<pair<string, string>> modified, int numAccounts)
{
    if (modified.empty())
    {
        cout << "There " << (numAccounts == 1 ? "is 1 account " : "are " + to_string(numAccounts) + " accounts ") << "and no account is modified" << endl;
        return;
    }

    cout << modified.size() << endl;
    for (int i = 0; i < modified.size(); ++i)
        cout << modified[i].first << ' ' << modified[i].second << endl;
}