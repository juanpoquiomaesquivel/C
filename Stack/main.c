#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JXStack.h"
#include "JXInput.h"

void free_integer(void *int_ptr)
{
    free(int_ptr);
}

int cmp_integer(const void *int_ptr1, const void *int_ptr2)
{
    const int *integer1 = (const int *)int_ptr1;
    const int *integer2 = (const int *)int_ptr2;

    return *integer1 == *integer2;
}

char *show_integer(const void *int_ptr)
{
    char buffer[1000];
    const int *integer = (const int *) int_ptr;
    sprintf(buffer, "Integer(%d)\n", *integer);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *str = strdup(buffer);

    if (str == NULL)
        exit(EXIT_FAILURE);

    return str;
}

int main()
{
    JXStack sta = {.top = NULL, .func_free = free_integer, .func_cmp = cmp_integer, .func_show = show_integer};
    int *numbers[5];

    for (size_t i = 0; i < 5; i++)
    {
        numbers[i] = (int *)jxi_input("%d", "Enter an integer!");
        jxs_push(&sta, numbers[i]);
    }

    jxs_show(sta);
    jxs_clear(&sta);

    return EXIT_SUCCESS;
}
