#include "sort.h"

/**
 * find_max - function to find the maximum element in the array
 * @array: integer array to check
 * @size: size of array
 * Return: On succes int
 */
int find_max(int *array, size_t size)
{
        int max = 0;
        size_t i;

        for (i = 0; i < size; i++)
        {
                if (array[i] > max)
                        max = array[i];
        }
        return (max);
}

/**
 * radix_sort - function to sort according to radix sort algorithm
 * @array: integer array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, *temp, count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i, j, exp = 1;

	if (!array || size < 2)
		return;

	max = find_max(array, size);
	temp = malloc(size * sizeof(int));

	while (max / exp > 0)
	{
		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10] += 1;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; i != (size_t)-1; i--)
		{
			j = (array[i] / exp) % 10;
			temp[count[j] - 1] = array[i];
			count[j]--;
		}
		for (i = 0; i < size; i++)
			array[i] = temp[i];
		print_array(array, size);
		exp *= 10;
	}
	free(temp);
}
