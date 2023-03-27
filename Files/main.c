#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writing_txt_file();
void reading_txt_file();

void writing_csv_file();
void reading_csv_file();

int main()
{
    // writing_txt_file();
    // reading_txt_file();
    // writing_csv_file();
    reading_csv_file();

    return EXIT_SUCCESS;
}

void writing_txt_file()
{
    FILE *f = fopen("myFavoriteSong.txt", "w");

    if (f == NULL)
        exit(EXIT_FAILURE);

    const char *lines[5];
    lines[0] = "As the hours pass\n";
    lines[1] = "I will let you know\n";
    lines[2] = "That I need to ask\n";
    lines[3] = "Before I'm alone\n";
    lines[4] = "How it feels to rest\n";

    for (size_t i = 0; i < 5; i++)
        fprintf(f, "%s", lines[i]);

    fclose(f);
}

void reading_txt_file()
{
    FILE *f = fopen("myFavoriteSong.txt", "r");

    if (f == NULL)
        exit(EXIT_FAILURE);

    char content[1000];

    while (fgets(content, 1000, f) != NULL)
        printf("%s", content);

    fclose(f);
}

void writing_csv_file()
{
    FILE *f = fopen("playlist.csv", "w");

    if (f == NULL)
        exit(EXIT_FAILURE);

    const char *columns[4];
    columns[0] = "Artist";
    columns[1] = "Song";
    columns[2] = "Year";
    columns[3] = "Calification";

    fprintf(f, "%s,%s,%s,%s\n", columns[0], columns[1], columns[2], columns[3]);

    const void *data[3][4];
    data[0][0] = "Mr.Kitty";
    data[0][1] = "After Dark";
    data[0][2] = "2016";
    double calf1 = 6.8;
    data[0][3] = &calf1;

    data[1][0] = "Martin Solveig";
    data[1][1] = "Hello";
    data[1][2] = "2013";
    double calf2 = 7.3;
    data[1][3] = &calf2;

    data[2][0] = "Rihanna";
    data[2][1] = "Umbrella";
    data[2][2] = "2011";
    double calf3 = 9.2;
    data[2][3] = &calf3;

    for (size_t i = 0; i < 3; i++)
        fprintf(f, "%s,%s,%s,%lf\n", (char *)data[i][0], (char *)data[i][1], (char *)data[i][2], *(double *)(data[i][3]));

    fclose(f);
}

void reading_csv_file()
{
    FILE *f = fopen("playlist.csv", "r");

    if (f == NULL)
        exit(EXIT_FAILURE);

    char buffer[1024];
    int row = 0;

    while (fgets(buffer, 1024, f))
    {
        row++;

        if (row == 1)
            continue;

        char *value = strtok(buffer, ",");

        while (value)
        {
            printf("%-20s", value);
            value = strtok(NULL, ",");
        }

        printf("\n");
    }

    fclose(f);
}
