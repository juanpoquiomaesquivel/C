#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JXQueue.h"

void fizzBuzz(size_t n);
bool isMultiple(int, int );

int main()
{
    fizzBuzz(30);

    return EXIT_SUCCESS;
}

void fizzBuzz(size_t n)
{
    JXQueue queue = {.root = NULL};
    size_t enough;

    for (int i = 1; i <= n; i++)
    {
        char *str;

        if (!isMultiple(i, 3) && !isMultiple(i, 5))
        {
            enough = (int) (log10(i) + 1) + 1;
            str = (char *)calloc(enough, sizeof(char));
            sprintf(str, "%d", i);
        }
        else
        {
            enough = 9;
            str = (char *)calloc(enough, sizeof(char));

            if (isMultiple(i, 3))
                strcat(str, "Fizz");

            if (isMultiple(i, 5))
                strcat(str, "Buzz");
        }

        jx_enqueue(&queue, str);
    }

    jx_show(queue);
    jx_clean(&queue);
}

bool isMultiple(int number, int multiple)
{
    return number % multiple == 0;
}
