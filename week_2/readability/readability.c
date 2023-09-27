#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calc_grade(string text);

int main(void)
{
    // Get the text
    string text = get_string("Enter the text: ");

    // Calc grade
    int grade = calc_grade(text);

    // Print result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int calc_grade(string text)
{
    int lettersInText = 0;
    int sentencesInText = 0;
    int wordsInText = 1;

    // Find the number of LETTERS in the text
    // Find the number of SENTENCES in the text
    // Find the number of WORDS in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            lettersInText++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencesInText++;
        }
        else if (text[i] == ' ')
        {
            wordsInText++;
        }
    }

    // Calc letters per 100 words
    float lettersPerWords = (float) lettersInText / (float) wordsInText * 100;

    // Calc Sentences per 100 words
    float sentencesPerWords = (float) sentencesInText / (float) wordsInText * 100;

    float grade = (0.0588 * lettersPerWords) - (0.296 * sentencesPerWords) - 15.8;

    return round(grade);
}