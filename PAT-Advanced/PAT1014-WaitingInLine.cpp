// PAT1014-WaitingInLine.cpp
// Ad
// Init: 19Apr04

/* -----------------------------------------------------------------------------

1014 Waiting in Line （30 分)

Suppose a bank has N windows open for service. 
There is a yellow line in front of the windows which devides the waiting area into two parts. 
The rules for the customers to wait in line are:

- The space inside the yellow line in front of each window is enough to contain a line with M customers. 
  Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
- Each customer will choose the shortest line to wait in when crossing the yellow line. 
  If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
- Customer_​i will take T_​i minutes to have his/her transaction processed.
- The first N customers are assumed to be served at 8:00am.

Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. 
There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. 
At 08:00 in the morning, customer1 is served at window1 while customer2 is served at window2.
Customer3 will wait in front of window1 and customer4 will wait in front of window2.
Customer5 will wait behind the yellow line.

At 08:01, customer1 is done is done and customer5 enters the line in front of window1 since that line seems shorter now.
Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally customer5 at 08:10.

### Input Specification:

Each input file contains one test case. 
Each case starts with a line containing 4 positive integers: 

- N (≤20, number of windows), 
- M (≤10, the maximum capacity of each line inside the yellow line), 
- K (≤1000, number of customers), 
- and Q (≤1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

### Output Specification:

For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. 
Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.

----------------------------------------
Sample Input:
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output:
08:07
08:06
08:10
17:00
Sorry
----------------------------------------

----------------------------------------------------------------------------- */

#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Time;
struct Customer;
deque<Customer> inputCustomers(int numCustomers);
map<int, Customer> calcFinishTime(deque<Customer> &outlineCustomers, int numQueues, int capacity, int numCustomers);
vector<int> inputQueries(int numQueries);
void printFinishTime(const vector<int> &queries, map<int, Customer> &finishedCustormers);

// Class -----------------------------------------------------------------------

struct Time
{
    int h;
    int m;

    Time() = default;
    Time(int hour, int minute) : h{hour}, m{minute}
    {
        if (m > 59)
        {
            h += m / 60;
            m %= 60;
        }
    }

    Time operator+(const Time &rhs) { return Time{h + rhs.h, m + rhs.m}; }

    bool operator<(const Time &rhs)
    {
        if (h < rhs.h)
            return true;
        else if (rhs.h < h)
            return false;
        else if (m < rhs.m)
            return true;
        else
            return false;
    }
};

struct Customer
{
    int id;
    Time needTime;
    Time finTime;

    Customer() : id{-1}, needTime{0, 0}, finTime{63336, 0} {}
    Customer(int i, int t) : id{i}, needTime{0, t}, finTime{65536, 0} {}
};

// Main ------------------------------------------------------------------------

// Score: 30/30.
// Runtime: 4 ms.
// Spent time: 170 min.

int main()
{
    int numQueues = 0, capacity = 0, numCustomers = 0, numQueries = 0;
    cin >> numQueues >> capacity >> numCustomers >> numQueries;

    deque<Customer> outlineCustomers = inputCustomers(numCustomers);

    map<int, Customer> finishedCustomers = calcFinishTime(outlineCustomers, numQueues, capacity, numCustomers);

    printFinishTime(inputQueries(numQueries), finishedCustomers);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

deque<Customer> inputCustomers(int numCustomers)
{
    deque<Customer> outlineCustomers;
    for (int i = 0; i < numCustomers; ++i)
    {
        int minute = 0;
        cin >> minute;
        outlineCustomers.push_back(Customer{i + 1, minute});
    }

    return outlineCustomers;
}

map<int, Customer> calcFinishTime(deque<Customer> &outlineCustomers, int numQueues, int capacity, int numCustomers)
{
    vector<deque<Customer>> inlineQueues(numQueues);
    vector<Time> queueTimes(numQueues, Time{8, 0});
    for (int i = 0; i < capacity; ++i)
        for (int j = 0; j < numQueues; ++j)
        {
            if (outlineCustomers.empty())
                break;

            auto customer = outlineCustomers.front();
            outlineCustomers.pop_front();
            customer.finTime = queueTimes[j] = queueTimes[j] + customer.needTime;
            inlineQueues[j].push_back(customer);
        }

    map<int, Customer> finishedCustomers;
    while (true)
    {
        bool emptyQueues = true;
        for (auto &q : inlineQueues)
            if (!q.empty())
            {
                emptyQueues = false;
                break;
            }
        if (emptyQueues)
            break;

        Time minTime{25, 0};
        int minQueue = 0;
        for (int j = 0; j < numQueues; ++j)
        {
            if (!inlineQueues[j].empty() && inlineQueues[j].front().finTime < minTime)
            {
                minTime = inlineQueues[j].front().finTime;
                minQueue = j;
            }
        }

        auto finishedCustomer = inlineQueues[minQueue].front();
        inlineQueues[minQueue].pop_front();
        finishedCustomers[finishedCustomer.id] = finishedCustomer;

        if (!outlineCustomers.empty())
        {
            auto nextCustomer = outlineCustomers.front();
            outlineCustomers.pop_front();
            nextCustomer.finTime = queueTimes[minQueue] = queueTimes[minQueue] + nextCustomer.needTime;
            inlineQueues[minQueue].push_back(nextCustomer);
        }
    }

    return finishedCustomers;
}

vector<int> inputQueries(int numQueries)
{
    vector<int> queries;
    for (int i = 0; i < numQueries; ++i)
    {
        int id;
        cin >> id;
        queries.push_back(id);
    }

    return queries;
}

void printFinishTime(const vector<int> &queries, map<int, Customer> &finishedCustomers)
{
    for (auto i : queries)
        if (finishedCustomers[i].finTime < Time{17, 0} + finishedCustomers[i].needTime)
            printf("%.2d:%.2d\n", finishedCustomers[i].finTime.h, finishedCustomers[i].finTime.m);
        else
            cout << "Sorry" << endl;
}
