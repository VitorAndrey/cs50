#include <cs50.h>
#include <stdio.h>
#include <string.h>

int asksHeigth(void);
void printPyramid(int heigth);

int main(void)
{
    // Asks the pyramid heigth
    int heigth = asksHeigth();

    // Prints the pyramig
    printPyramid(heigth);
}

int asksHeigth(void)
{
    int heigth;
    do
    {
        heigth = get_int("Enter the pyramid heigth: ");
    }
    while (heigth < 1 || heigth > 8);
    return heigth;
}

void printPyramid(int heigth)
{
    char space[] = " ";
    char hash[] = "#";

    int blankSpaces = heigth - 1;
    int hashCharacters = heigth - blankSpaces;
    do
    {
        char row[100] = "";

        for (int i = 0; i < blankSpaces; i++)
        {
            strcat(row, space);
        }
        for (int i = 0; i < hashCharacters; i++)
        {
            strcat(row, hash);
        }
        for (int i = 0; i < 2; i++)
        {
            strcat(row, space);
        }
        for (int i = 0; i < hashCharacters; i++)
        {
            strcat(row, hash);
        }
        printf("%s\n", row);
        blankSpaces--;
        hashCharacters++;
    }
    while (blankSpaces + 1 > 0);
}