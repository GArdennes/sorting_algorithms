#include "sort.h"

/**
 * hoare_partition - the partition
 * @array: the integer array
 * @low: low number
 * @high: high number
 * Return: On success int
 */
int hoare_partition(int *array, int low, int high)
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
 */
void quick_sort_hoare_recursive(int *array, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = hoare_partition(array, low, high);
		quick_sort_hoare_recursive(array, low, partition_index);
		quick_sort_hoare_recursive(array, partition_index + 1, high);
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

	quick_sort_hoare_recursive(array, 0, size - 1);
}
