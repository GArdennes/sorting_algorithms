#include "sort.h"

/**
 * bubble_sort - function that sorts using the Bubble sort algorithm
 * @array: integer array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	size_t temp;
	bool check_swp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		check_swp = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				check_swp = true;
			}
		}
		if (check_swp)
			print_array(array, size);
	}
}
