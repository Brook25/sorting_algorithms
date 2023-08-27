#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, k;
	int c, j, l;
	while (i < size)
	{
		k = i;
		c = array[k];
    		while (k < size)
    		{
        		if (c > array[k])
        		{
            			c = array[k];
            			j = k;
        		}
        		k++;
    		}

		if (c < array[i])
    		{
    			l = array[i];
    			array[i] = c;
    			array[j] = l;
    			print_array(array, size);
    		}
		i++;
	}
}
