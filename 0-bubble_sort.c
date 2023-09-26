#include "sort.h"

/**
 * bubble_sort - function that sorts using the Bubble sort algorithm
 * @array: integer array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j;
	size_t temp;
	bool check_swp;

	if (!array || size < 2)
		return;

	do {
		check_swp = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				check_swp = true;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	} while (check_swp);
}
