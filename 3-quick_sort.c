#include "sort.h"

size_t array_size;

void swap(int *start, int *end)
{
	int c;
	c = *start;
	*start = *end;
	*end = c;
}

size_t lomuto_partition(int *array, int lb, int ub)
{
	size_t i;
	int start = lb, end = ub;
        int pivot = array[ub];

	while (start < end)
	{
		while (start < ub && array[start] < pivot)
			start++;

		while (end > lb && array[end] >= pivot)
			end--;
		
		if (start < end)
		{
			swap(&array[start], &array[end]);
			for (i = 0; i < array_size - 1; i++)
				printf("%d, ", array[i]);
			printf("%d\n", array[i]);	
		}

	}

	swap(&array[start], &array[ub]);
	for (i = 0; i < array_size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	return start;
}

void quick(int *array, int lb, int ub)
{
	int pivot_ix;
	if (lb < ub)
	{
		pivot_ix = lomuto_partition(array, lb, ub);
		quick(array, lb, pivot_ix - 1);
		quick(array, pivot_ix + 1, ub);
	}
}


void quick_sort(int *array, size_t size)
{
	array_size = size;
	quick(array, 0, size - 1);
}
