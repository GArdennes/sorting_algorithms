#include "sort.h"

/**
 * shell_sort - function to sort according to shell sort algorithm
 * @array: integer array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	bool swapped;
	size_t gap, i, j;
	int temp;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		swapped = false;
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
				swapped = true;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;

		if (swapped)
			print_array(array, size);
	}
}
