// PAT1002-A+BForPolynomials.cpp
// Ad
// Init: 19Mar26

/* -----------------------------------------------------------------------------

1002 A+B for Polynomials （25 分)

This time, you are supposed to find A+B where A and B are two polynomials.

### Input Specification:

Each input file contains one test case. 
Each case occupies 2 lines, and each line contains the information of a polynomial:

K N1 aN1 N2 aN2 ... NK aNK

where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1,2,...,K) are the exponents and coefficients, respectively. 
It is given that 1≤K≤10，0≤NK<...<N2<N1<1000.

### Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input. 
Notice that there must be NO extra space at the end of each line. 
Please be accurate to 1 decimal place.

----------------------------------------
Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 2 1.5 1 2.9 0 3.2
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <map>

using namespace std;

void buildPoly(map<int, double> *poly);
void print(const map<int, double> &poly);

// Main ------------------------------------------------------------------------

// Score: 25/25.
// Runtime: 3 ms.
// Spent time: 40 min.

int main()
{
    map<int, double> poly;
    buildPoly(&poly);
    buildPoly(&poly);
    print(poly);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

void buildPoly(map<int, double> *poly)
{
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int N;
        double a;
        cin >> N >> a;
        (*poly)[N] += a;
        if ((*poly)[N] == 0)
            poly->erase(N);
    }
}

void print(const map<int, double> &poly)
{
    cout << poly.size();
    for (auto itr = poly.rbegin(); itr != poly.rend(); ++itr)
        printf(" %d %.1f", itr->first, itr->second);
    cout << endl;
}
