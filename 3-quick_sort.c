#include "sort.h"

/**
 * _swap - performs array swap
 * @array: integer array
 * @a: first
 * @b: second
 */
void _swap(int *array, size_t a, size_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - performs lomuto partition
 * @array: integer array
 * @low: low number
 * @high: high number
 * @size: size of array
 * Return: On success int
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				_swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		_swap(array, i, high);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_simple - performs quick sort algorithm
 * @array: integer array
 * @low: low number
 * @high: high number
 * @size: size of array
 */
void quick_sort_simple(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		quick_sort_simple(array, low, pivot - 1, size);
		quick_sort_simple(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - wrapper for quick sort algorithm
 * @array: integer array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	quick_sort_simple(array, 0, size - 1, size);
}
