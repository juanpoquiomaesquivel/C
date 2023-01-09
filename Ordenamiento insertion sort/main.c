#include <stdio.h>
#include <stdlib.h>

void ordenamiento_insertion_sort(int* arr, size_t n);
void mostrar(int *arr, size_t n);

int main()
{
    size_t N = 8;
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_insertion_sort(arr, N);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_insertion_sort(int *arr, size_t n)
{
    int aux, k;

    for (size_t i = 1; i < n; i++)
    {
        aux = arr[i];
        k = i - 1;

        while (k >= 0 && aux < arr[k])
        {
            arr[k + 1] = arr[k];
            k--;
        }

        arr[k + 1] = aux;
    }
}

void mostrar(int *arr, size_t n)
{
    printf("[ ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    puts("]");
}
