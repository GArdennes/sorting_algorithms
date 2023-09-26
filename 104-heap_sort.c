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
 * siftDown - function to sift down the tree
 * @array: integer array
 * @size: size of the array
 * @i: number
 * @total: size of the array in total
 */
void siftDown(int *array, size_t size, int i, size_t total)
{
	int largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, total);
		siftDown(array, size, largest, total);
	}
}

/**
 * build_heap - function to build heap
 * @array: integer array
 * @size: size of the array
 */
void build_heap(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 - 1; i != (size_t)-1; i--)
		siftDown(array, size, i, size);
}

/**
 * heap_sort - function to sort heap
 * @array: integer array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;
	build_heap(array, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		siftDown(array, i, 0, size);
	}
}
