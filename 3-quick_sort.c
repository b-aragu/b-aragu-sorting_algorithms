#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lomuto_partition(int *array, int low, int high, size_t size, int *i)
{
    if (low < high)
    {
        int pivot = array[high];
        int j = low - 1;

        for (int k = low; k <= high - 1; k++)
        {
            if (array[k] <= pivot)
            {
                j++;
                swap(&array[j], &array[k]);
                if (j != k) // Add this condition to avoid unnecessary prints
                    print_array(array, size);
            }
        }

        swap(&array[j + 1], &array[high]);
        if ((j + 1) != high) // Add this condition to avoid unnecessary prints
            print_array(array, size);

        *i = j + 1;
    }
}

void lomuto_sort(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int i = low;
        lomuto_partition(array, low, high, size, &i);
        lomuto_sort(array, size, low, i - 1);
        lomuto_sort(array, size, i + 1, high);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    lomuto_sort(array, size, 0, size - 1);
}
