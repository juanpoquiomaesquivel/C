#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JXQueue.h"
#include "JXInput.h"
#include "Student.h"

int main()
{
    JXQueue q = {.root = NULL, .func_free = free_student, .func_show = show_student};
    Student *stu[3];

    for (int i = 0; i < 3; i++)
    {
        puts("__________________");
        printf("STUDENT #%d\n", i + 1);
        stu[i] = new_student();
        jxq_enqueue(&q, stu[i]);
        puts("__________________");
    }

    jxq_show(q);
    jxq_clear(&q);

    return EXIT_SUCCESS;
}
