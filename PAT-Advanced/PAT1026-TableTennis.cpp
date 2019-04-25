// PAT1026-TableTennis.cpp
// Ad
// Init: 19Apr25

// Score: 0/30.
// Runtime: -.
// Spent time : 120 min.

/* -----------------------------------------------------------------------------

1026 Table Tennis （30 分)

A table tennis club has N tables available to the public. 
The tables are numbered from 1 to N. 
For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. 
If all the tables are occupied, they will have to wait in a queue. 
It is assumed that every pair of players can play for at most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. 
When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. 
However, if there is no VIP in the queue, the next pair of players can take it. 
On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.

### Input Specification:

Each input file contains one test case. 
For each case, the first line contains an integer N (≤10000) - the total number of pairs of players. 
Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. 
It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. 
It is assumed that no two customers arrives at the same time. 
Following the players' info, there are 2 positive integers: K (≤100) - the number of tables, and M (< K) - the number of VIP tables. 
The last line contains M table numbers.

### Output Specification:

For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. 
Then print in a line the number of players served by each table. 
Notice that the output must be listed in chronological order of the serving time. 
The waiting time must be rounded up to an integer minute(s). 
If one cannot get a table before the closing time, their information must NOT be printed.

----------------------------------------
Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Time;
struct Player;
struct Table;
set<Player> inputPlayers(void);
vector<Table> inputTables(void);
vector<Player> run(set<Player> &queue, vector<Table> &tables);
int getMinTable(const vector<Table> &tables);
set<Player>::iterator getFirstVip(set<Player> &queue);
void printPlayers(const vector<Player> &players);
void printTables(const vector<Table> &tables);

// Classes ---------------------------------------------------------------------

struct Time
{
    int h;
    int m;
    int s;

    Time(const string t) : h{stoi(t.substr(0, 2))}, m{stoi(t.substr(3, 2))}, s{stoi(t.substr(6, 2))} {}

    int operator-(const Time &rhs) const { return ((h - rhs.h) * 60 + m - rhs.m + ((s - rhs.s < 30) ? 0 : 1)); }
    Time operator+(int minute) const
    {
        Time ret = *this;
        ret.m += minute;
        ret.h += ret.m / 60;
        ret.m += ret.m % 60;

        return ret;
    }
    int operator<(const Time &rhs) const
    {
        if (h != rhs.h)
            return h < rhs.h;
        if (m != rhs.m)
            return m < rhs.m;
        return s < rhs.s;
    }
};

struct Player
{
    Time arrive;
    int playTime;
    bool vip;
    Time serve;

    Player(const string &at, int pt, int v) : arrive{at}, playTime{pt}, vip{(v == 1) ? true : false}, serve{"00:00:00"} {}

    bool operator<(const Player &rhs) const { return arrive < rhs.arrive; }
};

struct Table
{
    Time available;
    bool vip;
    int count;

    Table() : available{"08:00:00"}, vip{false}, count{0} {}
};

// Main ------------------------------------------------------------------------

int main()
{
    set<Player> queue = inputPlayers();
    vector<Table> tables = inputTables();

    vector<Player> players = run(queue, tables);

    printPlayers(players);
    printTables(tables);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

set<Player> inputPlayers(void)
{
    set<Player> ret;
    int numPlayers = 0;
    cin >> numPlayers;

    for (int i = 0; i < numPlayers; ++i)
    {
        string arriveTime;
        int playTime = 0, vip = 0;
        cin >> arriveTime >> playTime >> vip;
        ret.insert(Player{arriveTime, playTime, vip});
    }

    return ret;
}

vector<Table> inputTables(void)
{
    int numTables = 0, numVips = 0;
    cin >> numTables >> numVips;
    vector<Table> ret(numTables);

    for (int i = 0; i < numVips; ++i)
    {
        int v = 0;
        cin >> v;
        ret[v].vip = true;
    }

    return ret;
}

vector<Player> run(set<Player> &queue, vector<Table> &tables)
{
    vector<Player> finishedPlayers;

    while (!queue.empty())
    {
        int minTable = getMinTable(tables);
        if (minTable < 0)
            break;

        set<Player>::iterator nextPlayer = queue.end();
        if (tables[minTable].vip)
            nextPlayer = getFirstVip(queue);
        if (tables[minTable].available < nextPlayer->arrive)
            nextPlayer = queue.begin();

        finishedPlayers.push_back(*nextPlayer);
        queue.erase(nextPlayer);
        finishedPlayers.back().serve = (tables[minTable].available < nextPlayer->arrive) ? nextPlayer->arrive
                                                                                         : tables[minTable].available;
        tables[minTable].available = finishedPlayers.back().serve + finishedPlayers.back().playTime;
        tables[minTable].count++;
    }

    return finishedPlayers;
}

int getMinTable(const vector<Table> &tables)
{
    Time minAvailable{"25:00:00"};
    int minTable = -1;
    for (int i = 0; i < tables.size(); ++i)
        if (tables[i].available < minAvailable)
        {
            minAvailable = tables[i].available;
            minTable = i;
        }

    return (minAvailable < Time{"21:00:00"} ? minTable : -1);
}

set<Player>::iterator getFirstVip(set<Player> &queue)
{
    for (auto itr = queue.begin(); itr != queue.end(); ++itr)
        if (itr->vip)
            return itr;

    return queue.begin();
}

void printPlayers(const vector<Player> &players)
{
    for (auto &p : players)
        printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d\n", p.arrive.h, p.arrive.m, p.arrive.s, p.serve.h, p.serve.m, p.serve.s, p.serve - p.arrive);
}

void printTables(const vector<Table> &tables)
{
    cout << tables.front().count;
    for (int i = 1; i < tables.size(); ++i)
        cout << ' ' << tables[i].count;
    cout << endl;
}
