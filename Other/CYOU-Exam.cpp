// CYOU-Exam.cpp
// Ad147
// Init: 18Dec26
// Calculate sequence:
//  1,   4,   5,       16,  17,      20,      21         ...
// (4^0, 4^1, 4^0+4^1, 4^2, 4^0+4^2, 4^1+4^2, 4^0+4^1+4^2...)
// Input n k, output the kth number of sequence based on n.
// Example: 4 5, output: 17

// >>>>>>>>>>>>>>>>> not complete yet <<<<<<<<<<<<<<<<<

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    size_t n, k, ans = 1;
    std::vector<size_t> vec;
    vec.push_back(ans);
    std::cin >> n >> k;
    size_t no = 1, i = 1;
    while (true)
    {
        for (size_t j = 2; j < i + 1; ++j)
        {
            for (size_t l = 0; l < i - j + 1; ++l)
            {
                if (no == k)
                    break;
                ans = 0;
                for (size_t m = l; m < l + j; ++m)
                    ans += vec[m];
                std::cout << i << j << l << ans << std::endl;
                vec.push_back(ans);
                ++no;
            }
        }
        if (no == k)
            break;
        ans = 0;
        ans = std::pow(n, i);
        std::cout << 'a' << ans << std::endl;
        vec.push_back(ans);
        ++no;
        ++i;
    }
    std::cout << ans << std::endl;
    return 0;
}
