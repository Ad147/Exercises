// PAT1016-PhoneBills.cpp
// Ad
// Init: 19Apr06

// Score: 25/25.
// Spent time: 240 min.
// Runtime: 4 ms.

/* -----------------------------------------------------------------------------

1016 Phone Bills （25 分)

A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. 
When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. 
Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). 
Your job is to prepare the bills for each month, given a set of phone call records.

### Input Specification:

Each input file contains one test case. 
Each case has two parts: 

- the rate structure, 
- and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (≤1000), followed by N lines of records. 
Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (`mm:dd:hh:mm`), and the word `on-line` or `off-line`.

For each test case, all dates will be within a single month. 
Each `on-line` record is paired with the chronologically next record for the same customer provided it is an `off-line` record. 
Any `on-line` records that are not paired with an `off-line` record are ignored, as are `off-line` records not paired with an `on-line` record. 
It is guaranteed that at least one call is well paired in the input. 
You may assume that no two records for the same customer have the same time. 
Times are recorded using a 24-hour clock.

### Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. 
For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. 
Then for each time period of a call, print in one line the beginning and ending time and date (`dd:hh:mm`), the lasting time (in minute) and the charge of the call. 
The calls must be listed in chronological order. 
Finally, print the total charge for the month in the format shown by the sample.

----------------------------------------
Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
----------------------------------------

----------------------------------------------------------------------------- */

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

static vector<float> tolls;

struct DateTime;
struct CallRecord;
class Customer;

vector<float> inputTolls(void);
map<string, Customer> inputRecords(void);

// Classes ---------------------------------------------------------------------

struct DateTime
{
    int month;
    int d;
    int h;
    int m;

    DateTime() = default;
    DateTime(const string &input)
    {
        month = stoi(input.substr(0, 2));
        d = stoi(input.substr(3, 2));
        h = stoi(input.substr(6, 2));
        m = stoi(input.substr(9, 2));
    }

    bool operator<(const DateTime &rhs) const
    {
        if (d != rhs.d)
            return d < rhs.d;
        else if (h != rhs.h)
            return h < rhs.h;
        else
            return m < rhs.m;
    }
};

struct CallRecord
{
    DateTime beg;
    DateTime end;
    int duration;
    float fee;

    CallRecord() = default;
    CallRecord(const DateTime &b, const DateTime &e);
};

class Customer
{
  private:
    string mName;
    int mMonth;
    vector<CallRecord> mRecords;
    map<DateTime, bool> mInputRecords;
    float mTotalFees;

  public:
    Customer() = default;
    void inputRecord(const string &name, const string &datetime, const string &onoff);
    void printRecords(void);

  private:
    void buildRecords(void);
};

// Main ------------------------------------------------------------------------

int main()
{
    tolls = inputTolls();
    map<string, Customer> customers = inputRecords();

    for (auto &c : customers)
        c.second.printRecords();

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<float> inputTolls(void)
{
    vector<float> tolls;
    float toll = 0;
    for (int i = 0; i < 24; ++i)
    {
        cin >> toll;
        tolls.push_back(toll / 100);
    }

    return tolls;
}

map<string, Customer> inputRecords(void)
{
    map<string, Customer> customers;
    int numRecords = 0;
    cin >> numRecords;
    for (int i = 0; i < numRecords; ++i)
    {
        string name, datetime, onoff;
        cin >> name >> datetime >> onoff;
        customers[name].inputRecord(name, datetime, onoff);
    }

    return customers;
}

void Customer::inputRecord(const string &name, const string &datetime, const string &onoff)
{
    if (mName.empty())
        mName = name;
    mInputRecords[DateTime{datetime}] = (onoff == "on-line" ? true : false);
}

void Customer::printRecords(void)
{
    buildRecords();
    if (mRecords.empty())
        return;

    printf("%s %.2d\n", mName.c_str(), mMonth);
    for (auto &r : mRecords)
        printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d $%.2f\n",
               r.beg.d, r.beg.h, r.beg.m, r.end.d, r.end.h, r.end.m, r.duration, r.fee);
    printf("Total amount: $%.2f\n", mTotalFees);
}

void Customer::buildRecords(void)
{
    for (auto itrR = mInputRecords.begin(), itrL = itrR++;
         itrR != mInputRecords.end(); ++itrL, ++itrR)
        if (itrL->second && !itrR->second)
            mRecords.push_back(CallRecord{itrL->first, itrR->first});

    if (!mRecords.empty())
        mMonth = mRecords.front().beg.month;

    for (auto &r : mRecords)
        mTotalFees += r.fee;
}

CallRecord::CallRecord(const DateTime &b, const DateTime &e)
    : beg{b}, end{e}, duration{0}, fee{0.0}
{
    int he = e.h;
    if (b.d < e.d)
        he += 24 * (e.d - b.d);

    for (int h = b.h; h < he; ++h)
    {
        duration += 60;
        fee += tolls[h % 24] * 60;
    }

    duration = duration + e.m - b.m;
    fee = fee + tolls[e.h] * e.m - tolls[b.h] * b.m;
}
