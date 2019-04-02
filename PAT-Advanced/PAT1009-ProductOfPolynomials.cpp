// PAT1009-ProductOfPolynomials.cpp
// Ad
// Init: 19Apr02

/* -----------------------------------------------------------------------------

1009 Product of Polynomials （25 分)

This time, you are supposed to find A×B where A and B are two polynomials.

### Input Specification:

Each input file contains one test case. 
Each case occupies 2 lines, and each line contains the information of a polynomial:

K N_1 a_N1 N_2 a_N2 ... N_K a_NK

where K is the number of nonzero terms in the polynomial, N_i and a_Ni (i=1,2,⋯,K) are the exponents and coefficients, respectively. 
It is given that 1≤K≤10, 0≤N_K<...<N_2<N_1≤1000.

### Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. 
Notice that there must be NO extra space at the end of each line. 
Please be accurate up to 1 decimal place.

----------------------------------------
Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 3 3.6 2 6.0 1 1.6
----------------------------------------

----------------------------------------------------------------------------- */

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<int, double> inputPoly();
map<int, double> polyProduct(const map<int, double> &poly1, const map<int, double> &poly2);
void printPoly(const map<int, double> &poly);

// Main ------------------------------------------------------------------------

// Score: 25/25.
// Runtime: 4 ms.
// Spent time: 45 min.

int main()
{
    auto poly1 = inputPoly();
    auto poly2 = inputPoly();

    auto result = polyProduct(poly1, poly2);

    printPoly(result);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

map<int, double> inputPoly()
{
    map<int, double> ret;
    int K = 0;
    cin >> K;
    int Ni = 0;
    double ai = 0.0;
    for (int i = 0; i < K; ++i)
    {
        cin >> Ni >> ai;
        ret[Ni] = ai;
    }

    return std::move(ret);
}

map<int, double> polyProduct(const map<int, double> &poly1, const map<int, double> &poly2)
{
    map<int, double> res;
    for (auto &i1 : poly1)
        for (auto &i2 : poly2)
        {
            int exp = i1.first + i2.first;
            res[exp] += i1.second * i2.second;
            if (res[exp] == 0)
                res.erase(exp);
        }

    return res;
}

void printPoly(const map<int, double> &poly)
{
    cout << poly.size();
    for (auto itr = poly.rbegin(); itr != poly.rend(); ++itr)
        printf(" %d %.1f", itr->first, itr->second);
    cout << endl;
}
