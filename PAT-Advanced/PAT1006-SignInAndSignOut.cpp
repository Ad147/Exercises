// PAT1006-SignInAndSignOut.cpp
// Ad
// Init: 19Mar29

// Score: 25/25 (One-Shot Kill).
// Spent time: 40 min.
// Runtime: 3 ms.

/* -----------------------------------------------------------------------------

1006 Sign In and Sign Out （25 分)

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. 
Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

### Input Specification:

Each input file contains one test case. 
Each case contains the records for one day. 
The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time

where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

### Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. 
The two ID numbers must be separated by one space.

Note: 
It is guaranteed that the records are consistent. 
That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

----------------------------------------
Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>

using namespace std;

string getUnlockmanAndLockman();

// Classes ---------------------------------------------------------------------

class Time
{
  private:
    int hour;
    int minute;
    int second;

  public:
    Time(string time)
    {
        hour = stoi(time.substr(0, 2));
        minute = stoi(time.substr(3, 2));
        second = stoi(time.substr(6, 2));
    }

    bool operator<(const Time &rhs) const
    {
        if (hour != rhs.hour)
            return hour < rhs.hour;
        else if (minute != rhs.minute)
            return minute < rhs.minute;
        else
            return second < rhs.second;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    string unlockmanAndLockman = getUnlockmanAndLockman();

    cout << unlockmanAndLockman << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

string getUnlockmanAndLockman()
{
    string unlockman, lockman;
    Time unlockTime{"25:00:00"}, lockTime{"-1:00:00"};

    int recordNum = 0;
    cin >> recordNum;
    string id, signIn, signOut;
    for (int i = 0; i < recordNum; ++i)
    {
        cin >> id >> signIn >> signOut;
        Time signInTime{signIn}, signOutTime{signOut};

        if (signInTime < unlockTime)
        {
            unlockTime = signInTime;
            unlockman = id;
        }
        if (lockTime < signOutTime)
        {
            lockTime = signOutTime;
            lockman = id;
        }
    }

    return unlockman + ' ' + lockman;
}
