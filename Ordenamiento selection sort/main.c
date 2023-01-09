#include <stdio.h>
#include <stdlib.h>

void ordenamiento_selection_sort(int* arr, size_t n);
void mostrar(int *arr, size_t n);

int main()
{
    size_t N = 8;
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_selection_sort(arr, N);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_selection_sort(int *arr, size_t n)
{
    int aux, k;

    for (size_t i = 0; i < n - 1; i++)
    {
        k = i;

        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[k])
                k = j;

        aux = arr[k];
        arr[k] = arr[i];
        arr[i] = aux;
    }
}

void mostrar(int *arr, size_t n)
{
    printf("[ ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    puts("]");
}
