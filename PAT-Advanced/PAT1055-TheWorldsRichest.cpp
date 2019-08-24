// PAT1055-TheWorldsRichest.cpp
// Ad
// Init: 19Aug24

// Score: 22/25
// Time: 60'
// Runtime: 182 ms

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Person;
set<Person> getPeopleInAgeRange(const vector<int> &query, const unordered_map<int, vector<Person>> &people);

// Class -----------------------------------------------------------------------

struct Person
{
    string name;
    int age;
    int wealth;

    bool operator<(const Person &rhs) const
    {
        if (wealth != rhs.wealth)
            return wealth > rhs.wealth;
        else if (age != rhs.age)
            return age < rhs.age;
        else
            return name < rhs.name;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    int numPeople = 0, numQueries = 0;
    cin >> numPeople >> numQueries;
    unordered_map<int, vector<Person>> people;
    vector<vector<int>> queries;
    for (int i = 0; i < numPeople; ++i)
    {
        string name;
        int age = 0, wealth = 0;
        cin >> name >> age >> wealth;
        people[age].push_back({name, age, wealth});
    }

    for (int i = 0; i < numQueries; ++i)
    {
        int number = 0, Amin = 0, Amax = 0;
        cin >> number >> Amin >> Amax;
        queries.push_back({number, Amin, Amax});
    }

    for (size_t i = 0; i < queries.size(); ++i)
    {
        set<Person> result = getPeopleInAgeRange(queries[i], people);
        int minSize = result.size() < queries[i][0] ? result.size() : queries[i][0];

        cout << "Case #" << i + 1 << ":" << endl;
        if (minSize <= 0)
            cout << "None" << endl;

        auto itr = result.cbegin();
        for (int j = 0; j < minSize; ++j, ++itr)
            cout << itr->name << ' ' << itr->age << ' ' << itr->wealth << endl;
    }

    // system("pause");
    return 0;
}

// Function --------------------------------------------------------------------

set<Person> getPeopleInAgeRange(const vector<int> &query, const unordered_map<int, vector<Person>> &people)
{
    set<Person> ret;
    if (query.empty() || people.empty())
        return ret;

    for (int i = query[1]; i <= query[2]; ++i)
        if (people.find(i) != people.end())
            for (auto person : people.at(i))
                ret.insert(person);

    return ret;
}
