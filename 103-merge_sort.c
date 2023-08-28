#include "sort.h"


void merge(int array[], int lb, int mid, int ub)
{
	int i, left = lb, right = mid + 1, buf = 0;
	int *buffer;
	buffer = malloc(sizeof(int) * ((ub - lb) + 1));
	printf("[left]: ");
	for (i = lb; i < mid; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	printf("[right]: ");
	for (i = mid + 1; i < ub; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	while (left <= mid && right <= ub) {
		if (array[left] < array[right]) {
			buffer[buf] = array[left];
			left++; }
		else {
			buffer[buf] = array[right];
			right++; }
		buf++; }
	while (left <= mid) {
		buffer[buf] = array[left];
		buf++; left++; }
	while (right <= ub) {
		buffer[buf] = array[right];
		buf++; right++; }
	buf = 0; i = lb;
	while (i <= ub) {
		array[i] = buffer[buf];
		i++; buf++; }
	printf("[Done]: ");
	for (i = lb; i < ub; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	free(buffer); }


void _merge_sort(int array[], int lb, int ub)
{
	int mid = (lb + ub) / 2;
	if (lb >= ub)
		return;
	if (mid - lb == ub - mid)
		mid -= 1;
	_merge_sort(array, lb, mid);
	_merge_sort(array, mid + 1, ub);
	printf("Merging...\n");
	merge(array, lb, mid, ub);
}


void merge_sort(int *array, size_t size)
{
	int lower_bound = 0, upper_bound = size - 1;
	_merge_sort(array, lower_bound, upper_bound);
}

