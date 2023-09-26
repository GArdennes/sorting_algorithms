#include "sort.h"

/**
 * quick_sort - function to sort according to quick sort algorithm
 * @array: integer array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int pivot, temp;
	size_t i, j;

	if (size < 2 || !array)
		return;

	pivot = array[size - 1];
	i = -1;
	
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[size - 1];
	array[size - 1] = temp;

	quick_sort(array, i + 1);
	print_array(array, size);
	quick_sort(array + i + 2, size - i - 2);
	print_array(array, size);
}
