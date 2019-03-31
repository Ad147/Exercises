// PAT1008-Elevator.cpp
// Ad
// Init: 19Mar31

/* -----------------------------------------------------------------------------

1008 Elevator （20 分)

The highest building in our city has only one elevator. 
A request list is made up with N positive numbers. 
The numbers denote at which floors the elevator will stop, in specified order. 
It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. 
The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. 
The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

### Input Specification:

Each input file contains one test case. 
Each case contains a positive integer N, followed by N positive numbers. 
All the numbers in the input are less than 100.

### Output Specification:

For each test case, print the total time on a single line.

----------------------------------------
Sample Input:
3 2 3 1
Sample Output:
41
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

int getTotalTime();

// Main ------------------------------------------------------------------------

// Score: 20/20.
// Runtime: 3 ms.
// Spent time: 60 min (I did not notice that the first input is the number of floors, and paid (Q_Q)).

int main()
{
    int t = getTotalTime();

    cout << t << endl;

    // system("pause");
    return 0;
}

// Funtions --------------------------------------------------------------------

int getTotalTime()
{
    int ret = 0;
    int curr = 0, next = 0;
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> next;

        if (next > curr)
            ret += 6 * (next - curr);
        else
            ret += 4 * (curr - next);

        ret += 5;

        curr = next;
    }

    return ret;
}
