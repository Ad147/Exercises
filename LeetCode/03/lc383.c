/* lc383.c */

/* LeetCode 383. Ransom Note `E` */
/* 1sk | 92% | 6' */
/* A~0e27 */

bool canConstruct(char *ransomNote, char *magazine)
{
    int count[26] = {0};
    while (*ransomNote)
        count[*ransomNote++ - 'a']++;
    while (*magazine)
        count[*magazine++ - 'a']--;

    for (int i = 0; i < 26; i++)
        if (count[i] > 0)
            return false;

    return true;
}
