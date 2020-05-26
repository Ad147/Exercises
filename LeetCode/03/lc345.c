/* lc345.c */

/* LeetCode 345. Reverse Vowels of a String `E` */
/* acc | 100% | 12' */
/* A~0e26 */

char *reverseVowels(char *s)
{
    char *p1 = s;
    char *p2 = s + strlen(s) - 1;
    while (p1 < p2)
    {
        while (p1 < p2 &&
               *p1 != 'a' && *p1 != 'e' && *p1 != 'i' && *p1 != 'o' && *p1 != 'u' &&
               *p1 != 'A' && *p1 != 'E' && *p1 != 'I' && *p1 != 'O' && *p1 != 'U')
            p1++;
        while (p1 < p2 &&
               *p2 != 'a' && *p2 != 'e' && *p2 != 'i' && *p2 != 'o' && *p2 != 'u' &&
               *p2 != 'A' && *p2 != 'E' && *p2 != 'I' && *p2 != 'O' && *p2 != 'U')
            p2--;

        if (p1 >= p2)
            return s;

        char tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }

    return s;
}
