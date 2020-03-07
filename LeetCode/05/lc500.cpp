// lc500.cpp

// LeetCode 500 Keyboard Row `E`
// A~0c07
// 1sk | 100% | 25'

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> ret;
        if (words.size() == 0)
            return ret;

        set<char> row1 = {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'};
        set<char> row2 = {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'};
        set<char> row3 = {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'};

        for (int i = 0; i < words.size(); i++)
        {
            string &word = words[i];
            int row = 0;
            for (int j = 0; j < word.size(); j++)
            {
                int currRow = 0;
                if (row1.find(word[j]) != row1.end())
                    currRow = 1;
                else if (row2.find(word[j]) != row2.end())
                    currRow = 2;
                else if (row3.find(word[j]) != row3.end())
                    currRow = 3;
                else
                    throw exception();

                if (row == 0)
                    row = currRow;
                else if (currRow != row)
                {
                    row = -1;
                    break;
                }
            }

            if (row != -1)
                ret.push_back(word);
        }

        return ret;
    }
};
