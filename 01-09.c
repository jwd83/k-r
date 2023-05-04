#include <stdio.h>

int main()
{
    char c;
    int in_spaces = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            if(in_spaces == 0) {
                putchar(' ');
            }
            in_spaces = 1;
        } else {
            putchar(c);
            in_spaces = 0;
        }
    }
    return 0;
}