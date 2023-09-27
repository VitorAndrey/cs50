#include <cs50.h>
#include <stdio.h>

int askStartSize(void);
int askEndSize(int startSize);
int calcYearsTilThreshold(int startSize, int endSize);
void printYears(int startSize, int endSize, int yearsTilThreshold);

int main(void)
{
    // TODO: Prompt for start size
    int startSize = askStartSize();

    // TODO: Prompt for end size
    int endSize = askEndSize(startSize);

    // TODO: Calculate number of years until we reach threshold
    int yearsTilThreshold = calcYearsTilThreshold(startSize, endSize);

    // TODO: Print number of years
    printYears(startSize, endSize, yearsTilThreshold);
}

int askStartSize(void)
{
    int startSize;
    do
    {
        startSize = get_int("What's the Initial lhama's population? ");
    }
    while (startSize < 9);
    return startSize;
}

int askEndSize(int startSize)
{
    int endSize;
    do
    {
        endSize = get_int("What's the Final lhama's population? ");
    }
    while (endSize < startSize);
    return endSize;
}

int calcYearsTilThreshold(int startSize, int endSize)
{
    if (startSize == endSize)
    {
        return 0;
    }
    int yearsTilThreshold = 0;
    int population = startSize;
    do
    {
        yearsTilThreshold++;
        population = population + ((population / 3) - (population / 4));
    }
    while (population < endSize);
    return yearsTilThreshold;
}

void printYears(int startSize, int endSize, int yearsTilThreshold)
{
    printf("Start size: %i\nEnd size:%i\nYears: %i\n", startSize, endSize, yearsTilThreshold);
}