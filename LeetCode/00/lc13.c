/* lc13.c */

/* LeetCode 13. Roman to Integer `E` */
/* 1sk | 85%* | 16' */
/* A~0d05 */

int romanToInt(char *s)
{
    int ret = 0;
    while (*s != '\0')
    {
        switch (*s)
        {
        case 'I':
            if (*(s + 1) == 'V' || *(s + 1) == 'X')
                ret -= 1;
            else
                ret += 1;
            break;
        case 'V':
            ret += 5;
            break;
        case 'X':
            if (*(s + 1) == 'L' || *(s + 1) == 'C')
                ret -= 10;
            else
                ret += 10;
            break;
        case 'L':
            ret += 50;
            break;
        case 'C':
            if (*(s + 1) == 'D' || *(s + 1) == 'M')
                ret -= 100;
            else
                ret += 100;
            break;
        case 'D':
            ret += 500;
            break;
        case 'M':
            ret += 1000;
            break;
        default:
            break;
        }

        s++;
    }

    return ret;
}
