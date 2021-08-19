//Declaring required headers.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    // Declaring Variables
    long long creditCardNumber, sumDigit1, sumDigit2, sumDigit_11, sumDigit_12;
    long long creditDigit1, creditDigit2, sumFirst = 0, sumSecond = 0, sumDigit_21, sumDigit_22;
    long long totalSum, validity, numberOfDigits = 0;

    // Prompting user for inputs.
    do
    {
        creditCardNumber = get_long_long("Number: ");
    }
    while (creditCardNumber < 0);

    long long creditNumber = creditCardNumber;

    // Luhn's Algorithm : Step - 1
    long long creditFirstNumber = creditCardNumber / 10;
    while (creditFirstNumber > 0)
    {
        creditDigit1 = creditFirstNumber % 10;
        sumDigit1 = creditDigit1 * 2;
        creditFirstNumber = creditFirstNumber / 100;
        if (sumDigit1 > 9)
        {
            sumDigit_11 = sumDigit1 % 10;
            sumDigit_12 = sumDigit1 / 10;
            sumDigit1 = sumDigit_11 + sumDigit_12;
        }
        sumFirst = sumFirst + sumDigit1;
    }

    // Luhn's Algorithm : Step - 2
    long long creditSecondNumber = creditCardNumber;
    while (creditSecondNumber > 0)
    {
        creditDigit2 = creditSecondNumber % 10;
        sumDigit2 = creditDigit2;
        creditSecondNumber = creditSecondNumber / 100;
        if (sumDigit2 > 9)
        {
            sumDigit_21 = sumDigit2 % 10;
            sumDigit_22 = sumDigit2 / 10;
            sumDigit2 = sumDigit_21 + sumDigit_22;
        }
        sumSecond = sumSecond + sumDigit2;
    }

    // Luhn's Algorithm : Step - 3
    totalSum = sumFirst + sumSecond;
    validity = totalSum % 10;

    // Calculate number of digits.
    while (creditCardNumber > 0)
    {
        creditCardNumber = creditCardNumber / 10;
        numberOfDigits++;
    }

    // Other important notations.
    long long x = pow(10, numberOfDigits - 1);
    long long y = pow(10, numberOfDigits - 2);

    // Another step to check validity.
    long long firstOneDigit = creditNumber / x;
    long long firstTwoDigit = creditNumber / y;

    // Checking company name.
    if (validity == 0 && numberOfDigits == 15 && (firstTwoDigit == 34 || firstTwoDigit == 37))
    {
        printf("AMEX\n");
    }
    else if (validity == 0 && numberOfDigits == 16 && (firstTwoDigit == 51 || firstTwoDigit == 52 || firstTwoDigit == 53 || firstTwoDigit == 54 || firstTwoDigit == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (validity == 0 && (numberOfDigits == 13 || numberOfDigits == 16) && firstOneDigit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}