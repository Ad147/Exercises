// PAT1061-Dating.cpp
// Ad
// Init: 19Aug30

// Score: 18/20
// Time: 45'
// Runtime: 4 ms

#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void getCommonLetter(const string &str1, const string &str2, char &day, char &hour);
int getCommonLetterPosition(const string &str1, const string &str2);

const map<char, string> days{{'A', "MON"}, {'B', "TUE"}, {'C', "WED"}, {'D', "THU"}, {'E', "FRI"}, {'F', "SAT"}, {'G', "SUN"}};

// Main ------------------------------------------------------------------------

int main()
{
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;

    char day = 0, hour = 0;
    getCommonLetter(str1, str2, day, hour);
    int minute = getCommonLetterPosition(str3, str4);

    int h = (hour <= '9') ? (hour - '0') : (hour - 'A' + 10);
    cout << days.at(day) << ' ';
    printf("%.2d:%.2d\n", h, minute);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

void getCommonLetter(const string &str1, const string &str2, char &day, char &hour)
{
    int minSize = str1.size() < str2.size() ? str1.size() : str2.size();
    for (int i = 0; i < minSize; ++i)
        if (str1[i] == str2[i])
            if (day == 0 && 'A' <= str1[i] && str1[i] <= 'G')
                day = str1[i];
            else if (('0' <= str1[i] && str1[i] <= '9') || ('A' <= str1[i] && str1[i] <= 'N'))
                hour = str1[i];
}

int getCommonLetterPosition(const string &str1, const string &str2)
{
    int minSize = str1.size() < str2.size() ? str1.size() : str2.size();
    for (int i = 0; i < minSize; ++i)
        if (str1[i] == str2[i] && 'A' <= str1[i] && str1[i] <= 'z')
            return i;
}
