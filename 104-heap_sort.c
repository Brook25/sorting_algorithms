#include "sort.h"


size_t array_size;
/**
 * swap - swaps two values
 * @max: pointer to largest value
 * @i: pointer to lower value
 * Return: Nothing
 */
void swap(int* max, int* i)
{
	int c = *max;
	*max = *i;
	*i = c;
}

/**
 * max_heapify - re-build the array based
 * on a heap data structure
 * @array: array to be turned into a heap data struct
 * @size: size of array
 * @i: index to start heapifying from
 * Return: Nothing
 */
void max_heapify(int array[], size_t size, size_t i)
{
	size_t max = i, left = 2 * i + 1, right = 2 * i + 2, j;

	if (left < size && array[left] > array[max])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;
	if (max != i)
	{
	swap(&array[max], &array[i]);
	for (j = 0; j < array_size - 1; j++)
		printf("%d, ", array[j]);
	printf("%d\n", array[j]);
	max_heapify(array, size, max);
	}
}


/**
 * heap_sort - sorts an array using the heap sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */
void heap_sort(int array[], size_t size)
{
	size_t i, j;
	array_size = size;
	if (size > 1)
	{
		for (i = size / 2 - 1; i > 0; i--)
			max_heapify(array, size, i);
		max_heapify(array, size, i);
	
		for (i = size - 1; i > 0; i--)
		{
			swap(&array[0], &array[i]);
			for (j = 0; j < size - 1; j++)
				printf("%d, ", array[j]);
			printf("%d\n", array[j]);
			max_heapify(array, i, 0);
		}
	}
}
