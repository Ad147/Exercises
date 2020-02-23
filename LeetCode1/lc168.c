/* lc168.c */

/* LeetCode 168 Excel Sheet Column Title `E` */
/* A~0b23 */
/* osk | 58' | rt100% | mu100% */

char *convertToTitle(int n)
{
    char *title = (char *)calloc(10, sizeof(char));
    title += 9;
    *title-- = '\0';
    do
        *title-- = --n % 26 + 'A';
    while (n /= 26);

    return title + 1;
}
