// include required libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// main function declaration
int main(int argc, string argv[1])
{
    // convert string into integer using 'atoi' function of 'stdlib.h' library
    int key = atoi(argv[1]);

    // declare required variables
    char x, y;

    // checking input condition is valid or not
    if (argc == 2 && isdigit(*argv[1]))
    {
        // prompt to taking input from user
        string s = get_string("plaintext: ");
        // last line of the outpot
        printf("ciphertext: ");

        // starting the loop to check condition
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // small letters condition
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                x = (((s[i] - 'a') + key) % 26) + 'a';
                printf("%c", x);
            }
            // capital letters condition
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                y = (((s[i] - 'A') + key) % 26) + 'A';
                printf("%c", y);
            }
            // if above both condition fails then input print as it is
            else
            {
                printf("%c", s[i]);
            }
        }
    }
    // if user enter invalid input this block runs
    else
    {
        printf("Usage: ./caesar key");
    }
    printf("\n");
    // return statement
    return 0;
}