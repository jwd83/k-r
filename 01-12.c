#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
    char c;
    int in_spaces = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (in_spaces == OUT)
            {
                putchar('\n');
                in_spaces = IN;
            }
        }
        else
        {
            putchar(c);
            in_spaces = OUT;
        }
    }

    return 0;
}
