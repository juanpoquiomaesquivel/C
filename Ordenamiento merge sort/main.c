#include <stdio.h>
#include <stdlib.h>

void ordenamiento_merge_sort(int* arr, size_t lt, size_t rt);
void merge(int *sub_arr, size_t lt, size_t me, size_t rt);
void mostrar(int *arr, size_t n);

int main()
{
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    size_t N = sizeof(arr) / sizeof(arr[0]);
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_merge_sort(arr, 0, N - 1);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_merge_sort(int *arr, size_t lt, size_t rt)
{
    if (lt < rt)
    {
        int me = (rt + lt) / 2;
        ordenamiento_merge_sort(arr, lt, me);
        ordenamiento_merge_sort(arr, me + 1, rt);
        merge(arr, lt, me, rt);
    }
}

void merge(int *sub_arr, size_t lt, size_t me, size_t rt)
{
    size_t i, j, k;
    size_t n1 = me - lt + 1;
    size_t n2 = rt - me;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = sub_arr[lt+ i];

    for (j = 0; j < n2; j++)
        R[j] = sub_arr[me + 1 + j];

    i = 0;
    j = 0;
    k = lt;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            sub_arr[k] = L[i];
            i++;
        }
        else
        {
            sub_arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        sub_arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        sub_arr[k] = R[j];
        j++;
        k++;
    }
}

void mostrar(int *arr, size_t n)
{
    printf("[ ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    puts("]");
}
