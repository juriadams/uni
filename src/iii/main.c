#include <stdio.h>

int main()
{
    int i, j, rows;
    int count;

    printf("number of rows: ");
    scanf("%d", &rows);

    count = rows * 2 - 1;

    for (i = 1; i <= count; i++)
    {
        for (j = 1; j <= count; j++)
        {
            if (j == i || (j == count - i + 1))
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
        }

        printf("\n");
    }

    return 0;
}