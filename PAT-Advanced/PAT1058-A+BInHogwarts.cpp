// PAT1058-A+BInHogwarts.cpp
// Ad
// Init: 19Aug27

// Score: OSK/20
// Time: 15'
// Runtime: 2 ms

#include <cstdio>

using namespace std;

// Main ------------------------------------------------------------------------

int main()
{
    int ag = 0, as = 0, ak = 0, bg = 0, bs = 0, bk = 0;
    scanf("%d.%d.%d %d.%d.%d", &ag, &as, &ak, &bg, &bs, &bk);

    int sg = ag + bg, ss = as + bs, sk = ak + bk;
    if (sk >= 29)
    {
        sk %= 29;
        ++ss;
    }
    if (ss >= 17)
    {
        ss %= 17;
        ++sg;
    }

    printf("%d.%d.%d", sg, ss, sk);

    return 0;
}
