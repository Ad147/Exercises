/* lc520.c */

/* LeetCode 520. Detect Capital `E` */
/* 1sk | 100% | 10' */
/* A~0f20 */

bool detectCapitalUse(char *word)
{
    if (word[0] == 0)
        return true;
    else if (word[1] == 0)
        return true;

    int cap1 = isupper(word[0]);
    int cap2 = isupper(word[1]);
    if (cap1 && cap2)
    {
        while (*++word)
        {
            if (islower(*word))
                return false;
        }

        return true;
    }
    else if (cap1 && !cap2 || !cap1 && !cap2)
    {
        while (*++word)
        {
            if (isupper(*word))
                return false;
        }

        return true;
    }
    else
        return false;
}
