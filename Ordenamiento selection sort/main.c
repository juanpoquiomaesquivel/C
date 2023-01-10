#include <stdio.h>
#include <stdlib.h>

void ordenamiento_selection_sort(int* arr, size_t n);
void swap(int *a, int *b);
void mostrar(int *arr, size_t n);

int main()
{
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    size_t N = sizeof(arr) / sizeof(arr[0]);
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_selection_sort(arr, N);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_selection_sort(int *arr, size_t n)
{
    int k;

    for (size_t i = 0; i < n - 1; i++)
    {
        k = i;

        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[k])
                k = j;

        swap(&arr[k], &arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mostrar(int *arr, size_t n)
{
    printf("[ ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    puts("]");
}
