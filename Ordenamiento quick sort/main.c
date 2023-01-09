#include <stdio.h>
#include <stdlib.h>

void ordenamiento_quick_sort(int* arr, size_t ini, size_t fin);
int reduce_quick_sort(int *sub_arr, size_t ini, size_t fin);
void mostrar(int *arr, size_t n);

int main()
{
    size_t N = 8;
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_quick_sort(arr, 0, N - 1);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_quick_sort(int *arr, size_t ini, size_t fin)
{
    if (ini < fin)
    {
        int pi = reduce_quick_sort(arr, ini, fin);
        ordenamiento_quick_sort(arr, ini, pi - 1);
        ordenamiento_quick_sort(arr, pi + 1, fin);
    }
}

int reduce_quick_sort(int *sub_arr, size_t ini, size_t fin)
{
    int aux;
    int pvt = sub_arr[fin];
    int i = ini - 1;

    for (size_t j = ini; j < fin; j++)
        if (sub_arr[j] < pvt)
        {
            aux = sub_arr[j];
            sub_arr[j] = sub_arr[++i];
            sub_arr[i] = aux;
        }

    aux = sub_arr[++i];
    sub_arr[i] = sub_arr[fin];
    sub_arr[fin] = aux;

    return i;
}

void mostrar(int *arr, size_t n)
{
    printf("[ ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    puts("]");
}
