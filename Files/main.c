#include <stdio.h>
#include <stdlib.h>

void writingTxtFile();
void readingTxtFile();

void writingCsvFile();

int main()
{
    // writingTxtFile();
    // readingTxtFile();
    writingCsvFile();

    return EXIT_SUCCESS;
}

void writingTxtFile()
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

void readingTxtFile()
{
    FILE *f = fopen("myFavoriteSong.txt", "r");

    if (f == NULL)
        exit(EXIT_FAILURE);

    char content[1000];

    while (fgets(content, 1000, f) != NULL)
        printf("%s", content);

    fclose(f);
}

void writingCsvFile()
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

    const char *data[3][4];
    data[0][0] = "Mr.Kitty";
    data[0][1] = "After Dark";
    data[0][2] = "2016";
    data[0][3] = "6.8";

    data[1][0] = "Martin Solveig";
    data[1][1] = "Hello";
    data[1][2] = "2013";
    data[1][3] = "7.3";

    data[2][0] = "Rihanna";
    data[2][1] = "Umbrella";
    data[2][2] = "2011";
    data[2][3] = "9.2";

    for (size_t i = 0; i < 3; i++)
        fprintf(f, "%s,%s,%s,%s\n", data[i][0], data[i][1], data[i][2], data[i][3]);

    fclose(f);
}
