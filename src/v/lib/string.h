int strcmp(const char *str1, const char *str2)
{
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;

    unsigned char c1, c2;
    do
    {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);
    return c1 - c2;
}

int strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    return len;
}

int firstIndexOf(const char *str, const char *trgt)
{
    int fidx = -1;
    int idx = 0;

    while (str[idx] != '\0')
    {
        if (str[idx] == trgt[0])
        {
            fidx = idx;
            break;
        }

        idx++;
    }

    return fidx;
}

int lastIndexOf(const char *str, const char *trgt)
{
    int lidx = -1;
    int idx = 0;

    while (str[idx] != '\0')
    {
        if (str[idx] == trgt[0])
            lidx = idx;

        idx++;
    }

    return lidx;
}