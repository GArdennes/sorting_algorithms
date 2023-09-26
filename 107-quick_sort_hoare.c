#include "sort.h"

/**
 * swap - function to swap nodes
 * @a: number
 * @b: number
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - the partition
 * @array: the integer array
 * @low: low number
 * @high: high number
 * @size: size of the array
 * Return: On success int
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[low + (high  - low) / 2];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - function for recursive
 * @array: the integer array
 * @low: low number
 * @high: high number
 * @size: array size
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = hoare_partition(array, low, high, size);
		quick_sort_hoare_recursive(array, low, partition_index, size);
		quick_sort_hoare_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - quick sort algorithm
 * @array: the integer array
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
