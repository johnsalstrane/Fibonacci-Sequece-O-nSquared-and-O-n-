// This source file is to make two versions of a function that calculates the Fibonnacci Sequence.
// The first is the fully recursive version that will run very slowly with higher numbers, On squared.
//  The second will run On  by storing the results of previous calls into an array, to eliminate reduntant calculations.

#include <stdio.h>
#include <cstdlib>

int FabinocciSequenceOnSquared(int value)
{
    if (value <= 2) return 1;
    return(FabinocciSequenceOnSquared(value - 1) + FabinocciSequenceOnSquared(value - 2));
}

unsigned long long int FabinocciSequenceOn(const int value, unsigned long long int array[])
{
    if (value == 0) return 0;
    if (value <= 2) return 1;
    if (array[value] != 0) return array[value];
    array[value] = FabinocciSequenceOn(value - 1, array) + FabinocciSequenceOn(value - 2, array);
    return(array[value]);
}

int main(int argc, char *argv[])
{
    unsigned long long int array[100] = {};
    unsigned long long int result;
    int num = atoi(argv[1]);

    for (int i = 0; i < num; i++)
    {
        result = FabinocciSequenceOn(i, array);
        printf("%d: %llu\n", i+1, result);
    }

    return(0);
}