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
 * initialize_count_array - function to allocate and initialize count
 * @max: highest int
 * Return: On success *int
 */
int *initialize_count_array(int max)
{
	int *count, i;

	count = malloc((max + 1) * sizeof(int));

	if (count != NULL)
	{
		for (i = 0; i <= max; i++)
			count[i] = 0;
	}
	return (count);
}

/**
 * count_elements - function to populate count array
 * @array: integer array
 * @size: size of array
 * @count: count array
 */
void count_elements(const int *array, size_t size, int *count)
{
	size_t i;

	for (i = 0; i < size; i++)
		count[array[i]]++;
}

/**
 * update_count_array - function to update the count array
 * @count: count array
 * @max: max number
 */
void update_count_array(int *count, int max)
{
	int i;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
}

/**
 * counting_sort - function to sort according to sort algorithm
 * @array: integer array to check
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int *count, *temp, max;

	if (!array || size < 2)
		return;

	max = find_max(array, size);
	count = initialize_count_array(max);

	count_elements(array, size, count);
	update_count_array(count, max);

	print_array(count, max + 1);

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (i = size - 1; i != (size_t)-1; i--)
	{
		j = count[array[i]] - 1;
		temp[j] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(count);
	free(temp);
}

