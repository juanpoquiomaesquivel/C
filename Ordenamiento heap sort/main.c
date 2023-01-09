#include <stdio.h>
#include <stdlib.h>

void ordenamiento_heap_sort(int *arr, size_t n);
void heapify(int *sub_arr, size_t n, size_t i);
void swap(int *a, int *b);
void mostrar(int *arr, size_t n);

int main()
{
    size_t N = 8;
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_heap_sort(arr, N);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_heap_sort(int *arr, size_t n)
{
    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int *sub_arr, size_t n, size_t i)
{
    size_t lgt = i;
    size_t lt = 2 * i + 1;
    size_t rt = 2 * i + 2;

    if (lt < n && sub_arr[lt] > sub_arr[lgt])
        lgt = lt;

    if (rt < n && sub_arr[rt] > sub_arr[lgt])
        lgt = rt;

    if (lgt != i)
    {
        swap(&sub_arr[i], &sub_arr[lgt]);
        heapify(sub_arr, n, lgt);
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
