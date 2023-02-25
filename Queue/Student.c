#include "Student.h"
#include "JXInput.h"

Student *new_student()
{
    Student *stu = (Student *)malloc(sizeof(Student));

    if (stu == NULL)
        exit(EXIT_FAILURE);

    stu->name = jxi_input("%s", "What is this student's name?");
    stu->age = jxi_input("%d", "How old is this student?");
    stu->grade = jxi_input("%f", "What is the average grade of this student?");

    return stu;
}

void free_student(void *student)
{
    if (student != NULL)
    {
        Student *stu = (Student *)student;
        free(stu->name);
        free(stu->age);
        free(stu->grade);
        free(stu);
    }
}

char *show_student(const void *student)
{
    char buffer[1000];
    const Student *stu = (const Student *) student;
    sprintf(buffer, "Student(%s, %d, %.2f)\n", stu->name, *(stu->age), *(stu->grade));
    buffer[strcspn(buffer, "\n")] = '\0';
    char *str = strdup(buffer);

    if (str == NULL)
        exit(EXIT_FAILURE);

    return str;
}
