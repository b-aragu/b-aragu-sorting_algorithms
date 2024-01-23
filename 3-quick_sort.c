#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: Array to be sorted
 * @low: Lower index of the partition
 * @high: Upper index of the partition
 * @size: Size of the array
 * @i: Pointer to the current index (used as a parameter for recursion)
 */
void lomuto_partition(int *array, int low, int high, size_t size, int *i)
{
    if (low < high)
    {
        if (array[low] <= array[high])
        {
            swap(&array[*i], &array[low]);
            print_array(array, size);
            (*i)++;
        }
        lomuto_partition(array, low + 1, high, size, i);
    }
    else
    {
        swap(&array[*i], &array[high]);
        print_array(array, size);
    }
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort
 * @array: Array to be sorted
 * @low: Lower index of the partition
 * @high: Upper index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int i = low;
        lomuto_partition(array, low, high, size, &i);
        quick_sort_recursive(array, low, i - 1, size);
        quick_sort_recursive(array, i + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

