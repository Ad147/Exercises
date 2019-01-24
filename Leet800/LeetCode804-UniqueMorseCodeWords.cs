// LeetCode804-UniqueMorseCodeWords.cs
// Ad147 @Github
// Init: 19Jan24

/* -----------------------------------------------------------------------------

804. Unique Morse Code Words
Easy
String

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.  
For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-").  
We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
----------------------------------------
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
----------------------------------------

Note:
- The length of words will be at most 100.
- Each words[i] will have length in range [1, 12].
- words[i] will only consist of lowercase letters.

----------------------------------------------------------------------------- */


// Solution-0 ==================================================================

// Runtime: 108 ms, faster than 78.37% of C# online submissions for Unique Morse Code Words.
// `final`
// Algorithm: Traversal, HashSet.
// TimeComplexity: O(n), where n is the sum of the lengths of words.
// SpaceComplexity: O(n).

public class Solution
{
    public int UniqueMorseRepresentations(string[] words)
    {
        var uniqueMorse = new HashSet<string>();
        foreach (var word in words)
        {
            var morseCode = new StringBuilder();
            foreach (var ch in word) { morseCode.Append(mMorseTrans[ch]); }
            uniqueMorse.Add(morseCode.ToString());
        }
        return uniqueMorse.Count;
    }

    Dictionary<char, string> mMorseTrans = new Dictionary<char, string>
    {
        {'a', ".-"},
        {'b', "-..."},
        {'c', "-.-."},
        {'d', "-.."},
        {'e', "."},
        {'f', "..-."},
        {'g', "--."},
        {'h', "...."},
        {'i', ".."},
        {'j', ".---"},
        {'k', "-.-"},
        {'l', ".-.."},
        {'m', "--"},
        {'n', "-."},
        {'o', "---"},
        {'p', ".--."},
        {'q', "--.-"},
        {'r', ".-."},
        {'s', "..."},
        {'t', "-"},
        {'u', "..-"},
        {'v', "...-"},
        {'w', ".--"},
        {'x', "-..-"},
        {'y', "-.--"},
        {'z', "--.."},
    };
}
