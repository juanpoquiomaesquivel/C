#include <stdio.h>
#include <stdlib.h>

void ordenamiento_bubble_sort(int* arr, size_t n);
void swap(int *a, int *b);
void mostrar(int *arr, size_t n);

int main()
{
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    size_t N = sizeof(arr) / sizeof(arr[0]);
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_bubble_sort(arr, N);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_bubble_sort(int *arr, size_t n)
{
    for (size_t i = 1; i < n; i++)
        for (size_t j = n - 1; j >= i; j--)
            if (arr[j - 1] > arr[j])
                swap(&arr[j], &arr[j - 1]);
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
