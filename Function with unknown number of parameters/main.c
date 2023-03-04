#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double average(int n, ...);

int main()
{
    int n = 3;
    double avg = average(n, 11.256, 7.43, 1.28);
    printf("Average: %.3lf\n", avg);

    return EXIT_SUCCESS;
}

double average(int n, ...)
{
    va_list list_of_numbers;
    va_start(list_of_numbers, n);
    double avg = 0;

    for (int i = n; i > 0; i--)
    {
        double arg = va_arg(list_of_numbers, double);
        avg += arg;
    }

    avg /= n;
    va_end(list_of_numbers);

    return avg;
}

// #1 - https://stackoverflow.com/questions/10071186/function-with-unknown-number-of-parameters-in-c
// #2 - https://en.cppreference.com/w/c/variadic/va_start
// #3 - https://en.cppreference.com/w/c/variadic/va_arg
