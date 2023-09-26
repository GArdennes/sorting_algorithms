#include "sort.h"

/**
 * lomuto_partition - performs lomuto partition
 * @array: integer array
 * @low: low number
 * @high: high number
 * @swapped: check for swap
 * Return: On success size_t
 */
size_t lomuto_partition(int *array, size_t low, size_t high, bool *swapped)
{
	int pivot = array[high], temp;
	size_t i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			*swapped = true;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	*swapped = true;
	return (i + 1);
}

/**
 * quick_sort_simple - performs quick sort
 * @array: integer array
 * @low: low num
 * @high: high num
 * @size: size of array
 */
void quick_sort_simple(int *array, size_t low, size_t high, size_t size)
{
	bool swapped = false;
	int pivot_index;

	if (low < high)
	{
		swapped = false;
		pivot_index = lomuto_partition(array, low, high, &swapped);
		if (swapped)
			print_array(array, size);
		quick_sort_simple(array, low, pivot_index - 1, size);
		quick_sort_simple(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - wrapper function
 * @array: integer array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_simple(array, 0, size - 1, size);
}
