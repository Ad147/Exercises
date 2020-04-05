/* lc20.c */

/* LeetCode 20. Valid Parentheses `E` */
/* acc | 100% | 13' */
/* A~0d05 */

bool isValid(char *s)
{
    char stack[10000];
    char *p = stack;
    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
            *p++ = *s;
        else if (*s == ')')
        {
            if (p == stack || *--p != '(')
                return false;
        }
        else if (*s == ']')
        {
            if (p == stack || *--p != '[')
                return false;
        }
        else if (*s == '}')
        {
            if (p == stack || *--p != '{')
                return false;
        }

        s++;
    }

    if (p != stack)
        return false;
    else
        return true;
}
