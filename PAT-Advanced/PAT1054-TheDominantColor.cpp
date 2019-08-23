// PAT1054-TheDominantColor.cpp
// Ad
// Init: 19Aug23

// Score: 20/20
// Time: 20'
// Runtime: 158 ms

#include <iostream>
#include <unordered_map>

using namespace std;

int getDominantColor();

// Main ------------------------------------------------------------------------

int main()
{
    int dominColor = getDominantColor();
    if (dominColor != -1)
        cout << dominColor << endl;
    else
        throw exception();

    return 0;
}

// Function --------------------------------------------------------------------

int getDominantColor()
{
    int width = 0, height = 0;
    cin >> width >> height;
    int halfPixels = width * height / 2;

    unordered_map<int, int> colors;
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
        {
            int color = 0;
            cin >> color;
            if (++colors[color] > halfPixels)
                return color;
        }

    return -1;
}