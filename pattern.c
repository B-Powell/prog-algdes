//Name:         Bryan Powell
//FileName:     pattern.c
//Description:  locates a user-defined pattern inside a string from the user

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int contains (const char *text, const char *pattern);

int main ()
{
    const char text[81], pattern[80];
    int i = 0, results = -1;

    for (i; i < 5; i++)
    {
        printf("Please input a string to test: \n");
        fflush(stdin);
        fgets(text, 39, stdin);

        printf("Please input a pattern to search for: \n");
        fflush(stdin);
        fgets(pattern, 39, stdin);

        results = contains (text, pattern);

        if (results == -1)
            printf("Pattern not found");

        else
            printf("Pattern %s occurs in %s at the location %d.\n", pattern, text, results);

        results = -1;
        printf("\n");
    }

    return 0;
}

int contains (const char *text, const char *pattern)
{
    int i = 0, j = 0, start_of_pattern;
    bool match_found = false;


    for (i; i < 40; i++)
    {

        for (j; ((j < sizeof(pattern)) && (pattern[j] != '\n')); j++)
        {
            if ((sizeof(pattern) - j) > (sizeof(text)-i))
            {
                match_found = false;
                break;
            }
            if (pattern[j]== text[i+j])
            {
                if (j == 0)
                    start_of_pattern = i;
                i++;
                match_found = true;
            }
            if (pattern[j] != text[i+j])
                match_found = false;
        }

        if (match_found = false)
            start_of_pattern = -1;

    }

    return start_of_pattern;
}
