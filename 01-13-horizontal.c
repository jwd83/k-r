#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_WORD_LENGTH 255
#define NOT_A_TERMINATOR 0
#define IS_A_TERMINATOR 1

int main()
{
    char c;
    int word_length = 0;
    int length_count[MAX_WORD_LENGTH];
    char *terminators = " \n\t.,!=+?;|&-()[]{}<>\"'";
    int is_terminator = NOT_A_TERMINATOR;

    printf("Send ALT+255 to end input\nPaste Input:");

    // set all counts to 0
    for (int i = 0; i < MAX_WORD_LENGTH; ++i)
        length_count[i] = 0;

    while ((c = getchar()) != EOF)
    {
        // check if c is a terminator
        is_terminator = NOT_A_TERMINATOR;

        for (int i = 0; terminators[i] != '\0'; ++i)
        {
            if (c == terminators[i])
            {
                is_terminator = IS_A_TERMINATOR;
                break;
            }
        }

        if (is_terminator == IS_A_TERMINATOR)
        {
            if (word_length > 0 && word_length < MAX_WORD_LENGTH)
            {
                length_count[word_length]++;
            }
            word_length = 0;
        }
        else
        {
            word_length++;
        }
    }

    if (word_length > 0 && word_length < MAX_WORD_LENGTH)
    {
        length_count[word_length]++;
        word_length = 0;
    }

    for (int i = 1; i < MAX_WORD_LENGTH; ++i)
    {
        if (length_count[i] == 0)
            continue;
        printf("%4d: ", i);
        for (int j = 0; j < length_count[i]; ++j)
        {
            printf("*");
        }
        printf("\t%d\n", length_count[i]);
    }

    return 0;
}
