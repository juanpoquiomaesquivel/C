#include "JXInput.h"

void *jxi_input(const char *fmt, const char *msg)
{
    void *ptr;

    if (msg != NULL)
        puts(msg);

    size_t dtype = strcspn("dflcs", fmt);

    switch (dtype)
    {
    case JXI_INTEGER:
        ptr = malloc(sizeof(int));
        break;
    case JXI_FLOAT:
        ptr = malloc(sizeof(float));
        break;
    case JXI_DOUBLE:
        ptr = malloc(sizeof(double));
        break;
    case JXI_CHARACTER:
        ptr = malloc(sizeof(char));
        break;
    case JXI_STRING:
        printf(">> ");
        char buffer[1000];
        fgets(buffer, 1000, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        ptr = strdup(buffer);
        break;
    }

    if (ptr == NULL)
        exit(EXIT_FAILURE);

    if (dtype == JXI_STRING)
        return ptr;

    int flag = -1;

    do
    {
        printf(">> ");

        switch (dtype)
        {
        case JXI_INTEGER:
            flag = scanf(fmt, (int *)ptr);
            break;
        case JXI_FLOAT:
            flag = scanf(fmt, (float *)ptr);
            break;
        case JXI_DOUBLE:
            flag = scanf(fmt, (double *)ptr);
            break;
        case JXI_CHARACTER:
            flag = scanf(fmt, (char *)ptr);
            break;
        }

        if (!feof(stdin) && !ferror(stdin))
            while (getchar() != '\n')
                ;
    }
    while (!flag);

    return ptr;
}
