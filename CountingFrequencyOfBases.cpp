#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int finding_base(long unsigned int);

int finding_base(long unsigned int num)
{
    int r, large = 0; // r=remainder
    while (num != 0)
    {
        r = num % 10; // This will divide the num by 10, and then store the remainder, hence will give the last digit in a number
        if (r > large)
        {
            large = r;
        }
        num = num / 10;  // this will remove the last digit in the num and afterwards store tha new value
    }
    return large;
}

int main()
{
    long unsigned int array[50];
    int i, j;
    long unsigned int random_number;
    int base, final_base;
    int frequency_of_bases[11] = {0}; // initialising each element of this array with 0 value

    srand(time(NULL));       // The srand function is used to seed the random number generator with the
                             //  current time, ensuring different random numbers on each program run.

    for (i = 0; i < 50; i++) // generating an array consisting of 50 random numbers
    {
        array[i] = rand() % 4999999 + 5000000000;
    }

    printf("the list of numbers:\n"); // printing the array of randomly generated integers
    for (i = 0; i < 50; i++)
    {
        printf("%lu\n", array[i]);
    }

    printf(" \n\n ");

    for (i = 0; i < 50; i++)
    {
        random_number = array[i];           // storing each element of array in a integer variable 'random_number'
        base = finding_base(random_number); // calling the function and storing the result('large' value) in base
        final_base = base + 1;
        printf("the Highest base of number %lu is %d\n", array[i], final_base);

        for (j = 0; j < 11; j++)
        {
            if (final_base == j)
            {
                frequency_of_bases[j]++;
            }
        }
    }

    // Print the frequency distribution chart
    printf("\n\nFREQUENCY DISTRIBUTION CHART\n\n");
    printf("\nbase0\tbase1\tbase2\tbase3\tbase4\tbase5\tbase6\tbase7\tbase8\tbase9\tbase10");
    printf("\n\n");
    for (j = 0; j < 11; j++)
    {
        printf("%d\t", frequency_of_bases[j]);
    }
    return 0;
}
