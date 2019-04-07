// PAT1017-QueueingAtBank.cpp
// Ad
// Init: 19Apr07

// Score: 25/25.
// Runtime: 22 ms.
// Spent time: 150 min.

/* -----------------------------------------------------------------------------

1017 Queueing at Bank （25 分)

Suppose a bank has K windows open for service. 
There is a yellow line in front of the windows which devides the waiting area into two parts. 
All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. 
It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10^​4) - the total number of customers, and K (≤100) - the number of windows. 
Then N lines follow, each contains 2 times: `HH:MM:SS` - the arriving time, and P - the processing time in minutes of a customer. 
Here HH is in the range [00, 23], MM and SS are both in [00, 59]. 
It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. 
Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

### Output Specification:

For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

----------------------------------------
Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
----------------------------------------

----------------------------------------------------------------------------- */

#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Time;
struct Customer;

deque<Customer> inputCustomers(int numCustomers);
double getTotalWait(deque<Customer> &outLine, int numWindows);

// Classes ---------------------------------------------------------------------

struct Time
{
    int h;
    int m;
    int s;

    Time() = default;
    Time(int hi, int mi, int si) : h{hi}, m{mi}, s{si} {}
    Time(const string &t) : h{stoi(t.substr(0, 2))}, m{stoi(t.substr(3, 2))}, s{stoi(t.substr(6, 2))} {}

    bool operator<(const Time &rhs) const
    {
        if (h != rhs.h)
            return h < rhs.h;
        else if (m != rhs.m)
            return m < rhs.m;
        else
            return s < rhs.s;
    }

    Time operator+(int minute) const { return Time{h + (m + minute) / 60, (m + minute) % 60, s}; }
    double operator-(const Time &rhs) const { return (h - rhs.h) * 60 + (m - rhs.m) + (s - rhs.s) / 60.0; }
};

struct Customer
{
    Time arrive;
    int process;

    Customer() = default;
    Customer(const string &t, int p) : arrive{t}, process{p} {}

    bool operator<(const Customer &rhs) const { return arrive < rhs.arrive; }
};

// Main ------------------------------------------------------------------------

int main()
{
    int numCustomers = 0, numWindows = 0;
    cin >> numCustomers >> numWindows;
    if (!numCustomers || !numWindows)
    {
        cout << "0.0" << endl;
        return 0;
    }

    deque<Customer> outLine = inputCustomers(numCustomers);
    sort(outLine.begin(), outLine.end());

    numCustomers = outLine.size();
    double totalWait = getTotalWait(outLine, numWindows);

    printf("%.1f\n", totalWait / numCustomers);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

deque<Customer> inputCustomers(int numCustomers)
{
    deque<Customer> outLine;
    for (int i = 0; i < numCustomers; ++i)
    {
        string arrive;
        int process = 0;
        cin >> arrive >> process;
        if (Time{arrive} < Time{"17:00:01"})
            outLine.push_back(Customer{arrive, process});
    }

    return outLine;
}

double getTotalWait(deque<Customer> &outLine, int numWindows)
{
    double totalWait = 0.0;
    vector<Time> inLine(numWindows, Time{8, 0, 0});
    while (!outLine.empty())
    {
        Time minTime{65536, 0, 0};
        int minWindow = -1;
        for (int i = 0; i < numWindows; ++i)
            if (inLine[i] < minTime)
            {
                minTime = inLine[i];
                minWindow = i;
            }

        if (outLine.front().arrive < inLine[minWindow])
            totalWait += inLine[minWindow] - outLine.front().arrive;
        else
            inLine[minWindow] = outLine.front().arrive;

        inLine[minWindow] = inLine[minWindow] + outLine.front().process;
        outLine.pop_front();
    }

    return totalWait;
}
