#include <stdio.h>
#include <stdlib.h>

void ordenamiento_shell_sort(int* arr, size_t n);
void mostrar(int *arr, size_t n);

int main()
{
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    size_t N = sizeof(arr) / sizeof(arr[0]);
    puts("Array desordenado =>");
    mostrar(arr, N);
    ordenamiento_shell_sort(arr, N);
    puts("\nArray ordenado =>");
    mostrar(arr, N);

    return EXIT_SUCCESS;
}

void ordenamiento_shell_sort(int *arr, size_t n)
{
    int aux, k;

    for (size_t rzn = n / 2; rzn > 0; rzn /= 2)
    {
        for (size_t i = rzn; i < n; i++)
        {
            aux = arr[i];
            k = i - rzn;

            while (k >= 0 && aux < arr[k])
            {
                arr[k + rzn] = arr[k];
                k -= rzn;
            }

            arr[k + rzn] = aux;
        }
    }
}

void mostrar(int *arr, size_t n)
{
    printf("[ ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    puts("]");
}
