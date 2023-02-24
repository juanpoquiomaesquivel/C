#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char *name;
    int *age;
    float *grade;
} Student;

Student *new_student();
void free_student(void *stu);
char *show_student(const void *stu);

#endif // STUDENT_H_INCLUDED
