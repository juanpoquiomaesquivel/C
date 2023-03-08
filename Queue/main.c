#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JXQueue.h"
#include "JXInput.h"

enum
{
    EXIT,
    ENQUEUE,
    DEQUEUE,
    PEEK,
    CLEAR,
    IS_EMPTY,
    SHOW
};

const char menu_list[][100] = {"Exit",
                           "Enqueue",
                           "Dequeue",
                           "Peek",
                           "Clear",
                           "Is empty?",
                           "Show"
                          };

void menu();
void free_integer(void *int_ptr);
int cmp_integer(const void *int_ptr1, const void *int_ptr2);
char *show_integer(const void *int_ptr);

int main()
{
    menu();

    return EXIT_SUCCESS;
}

void menu()
{
    const size_t n = sizeof(menu_list) / sizeof(menu_list[0]);
    int *option = NULL;
    JXQueue que = {.root = NULL, .func_free = free_integer, .func_cmp = cmp_integer, .func_show = show_integer};
    void *info = NULL;

    while (true)
    {
        system("cls");
        puts("\n\t\t.: QUEUE :.\n");

        for (size_t i = 0; i < n; i++)
            printf("[%d] : %s\n", i, menu_list[i]);

        puts("");
        option = (int *)jxi_input("%d", "Enter an option!");

        switch (*option)
        {
        case EXIT:
            jxq_clear(&que);
            free(option);
            puts("Program finished!");

            return;
        case ENQUEUE:
            info = (int *)jxi_input("%d", "Enter an integer!");
            jxq_enqueue(&que, info);
            info = NULL;
            break;
        case DEQUEUE:
            jxq_dequeue(&que);
            break;
        case PEEK:
            info = jxq_peek(que);
            (info != NULL) ? printf("%s\n", show_integer(info)) : puts("There's no info.");
            info = NULL;
            break;
        case CLEAR:
            jxq_clear(&que);
            break;
        case IS_EMPTY:
            printf("%It is%s empty\n", (jxq_is_empty(que) ? "" : " not"));
            break;
        case SHOW:
            jxq_show(que);
            break;
        default:
            puts("Choose a correct option!");
        }

        free(option);
        option = NULL;
        system("pause");
    }
}

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
