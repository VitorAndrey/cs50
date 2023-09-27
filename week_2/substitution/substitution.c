#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string encrypt(string key, string plainText);
int validateKey(string key);

int main(int argc, string argv[])
{
    // Get the key
    string key = argv[1];

    // Validate key
    int isKeyValid = validateKey(key);

    if (argc != 2 || isKeyValid == 1)
    {
        // Invalid argument error
        printf("You must pass one 26 length command-line argument.\n");
        return 1;
    }
    else if (isKeyValid == 0)
    {
        // Get the plain text
        string plainText = get_string("plaintext:  ");

        // Encrypt the Message
        string ecryptedMessage = encrypt(key, plainText);

        // Print result
        printf("ciphertext: %s\n", ecryptedMessage);
    }
}

int validateKey(string key)
{
    if (key != NULL)
    {
        if (strlen(key) != 26)
        {
            return 1;
        }

        int charCount[26] = {0};

        for (int i = 0; i < 26; i++)
        {
            if (!isalpha(key[i]))
            {
                return 1;
            }

            int index = toupper(key[i]) - 'A';

            if (charCount[index] > 0)
            {
                return 1;
            }

            charCount[index]++;
        }

        return 0;
    }
    else
    {
        return 1;
    }
}

string encrypt(string key, string plainText)
{
    string cipherText = plainText;

    for (int i = 0, len = strlen(plainText); i < len; i++)
    {

        if (isalpha(plainText[i]))
        {
            int index = tolower(plainText[i]) - 'a';

            if (islower(plainText[i]))
            {
                cipherText[i] = tolower(key[index]);
            }
            else if (isupper(plainText[i]))
            {
                cipherText[i] = toupper(key[index]);
            }
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }

    return cipherText;
}