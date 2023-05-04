#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_WORD_LENGTH 20

int main()
{
    char c;
    int word_length = 0;
    int length_count[MAX_WORD_LENGTH];

    // set all counts to 0
    for (int i = 0; i < MAX_WORD_LENGTH; ++i)
        length_count[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ';')
        {

            if (word_length > 0 && word_length < MAX_WORD_LENGTH)
            {
                length_count[word_length]++;
                word_length = 0;
            }
            break;
        }

        if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' || c == '!' || c == '?')
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

    for (int i = 1; i < MAX_WORD_LENGTH; ++i)
    {
        if (length_count[i] == 0)
            continue;
        printf("%d: ", i);
        for (int j = 0; j < length_count[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
