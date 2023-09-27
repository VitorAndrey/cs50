#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_long_as_string(string question);
void verify_card(string cardNumber);

int main(void)
{
    // Gets the number as long and parse it to string
    string cardNumber = get_long_as_string("What's your card number? ");

    // Verify the card
    verify_card(cardNumber);
}

string get_long_as_string(string question)
{
    long n = get_long("%s", question);
    string cardNumber = malloc(20 * sizeof(char));
    if (cardNumber != NULL)
    {
        sprintf(cardNumber, "%ld", n);
    }
    return cardNumber;
}

void verify_card(string cardNumber)
{
    int result = 0;

    // Multiply every other digit by 2, starting with the number’s second-to-last digit,
    // and then add those products’ digits together.
    int evenSum = 0;
    for (int i = (strlen(cardNumber) - 2); i >= 0; i -= 2)
    {
        int cardNumberDigit = cardNumber[i] - '0';
        int digit = cardNumberDigit;
        digit = digit * 2;
        if (digit > 9)
        {
            int sum = 0;
            while (digit != 0)
            {
                sum += digit % 10;
                digit /= 10;
            }
            digit = sum;
        }
        evenSum += digit;
    }
    result += evenSum;

    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    int oddSum = 0;
    for (int i = (strlen(cardNumber) - 1); i >= 0; i -= 2)
    {
        int cardNumberDigit = cardNumber[i] - '0';
        oddSum += cardNumberDigit;
    }
    result += oddSum;

    // Can divide by 10?
    if (result % 10 != 0 || !(strlen(cardNumber) >= 13 && strlen(cardNumber) <= 19))
    {
        printf("INVALID\n");
    }
    else
    {
        // Get the first two digits
        int firstTwoDigits = (cardNumber[0] - '0') * 10 + (cardNumber[1] - '0');

        string cardType = "INVALID";

        // Check AMEX
        int amexNumbers[] = {34, 37};
        for (int i = 0; i < sizeof(amexNumbers) / sizeof(amexNumbers[0]); i++)
        {
            if (firstTwoDigits == amexNumbers[i])
            {
                cardType = "AMEX";
                break;
            }
        }

        // Check MASTERCARD
        int masterNumbers[] = {51, 52, 53, 54, 55};
        for (int i = 0; i < sizeof(masterNumbers) / sizeof(masterNumbers[0]); i++)
        {
            if (firstTwoDigits == masterNumbers[i])
            {
                cardType = "MASTERCARD";
                break;
            }
        }

        // Check VISA
        if ((firstTwoDigits / 10) == 4)
        {
            cardType = "VISA";
        }

        printf("%s\n", cardType);
    }
}
