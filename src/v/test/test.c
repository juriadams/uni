#include <stdio.h>

#include "../lib/string.h"

int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    char str3[] = "moin welt";

    printf("\nstrcmp(\"%s\", \"%s\") -> %d\n", str1, str2, strcmp(str1, str2));
    printf("strcmp(\"%s\", \"%s\") -> %d\n", str1, str3, strcmp(str1, str3));
    printf("strcmp(\"%s\", \"%s\") -> %d\n", str3, str1, strcmp(str3, str1));

    printf("\nstrlen(\"%s\") -> %d\n", str1, strlen(str1));
    printf("strlen(\"%s\") -> %d\n", str3, strlen(str3));

    printf("\nfirstIndexOf(\"%s\", \"%s\") -> %d\n", str1, "o", firstIndexOf(str1, "o"));
    printf("firstIndexOf(\"%s\", \"%s\") -> %d\n", str3, "o", firstIndexOf(str3, "o"));
    printf("firstIndexOf(\"%s\", \"%s\") -> %d\n", str3, "y", firstIndexOf(str3, "y"));

    printf("\nlastIndexOf(\"%s\", \"%s\") -> %d\n", str1, "o", lastIndexOf(str1, "o"));
    printf("lastIndexOf(\"%s\", \"%s\") -> %d\n", str3, "o", lastIndexOf(str3, "o"));
    printf("lastIndexOf(\"%s\", \"%s\") -> %d\n", str3, "y", lastIndexOf(str3, "y"));

    return 0;
}