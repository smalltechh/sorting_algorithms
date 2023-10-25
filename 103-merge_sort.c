#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - A function to sort the subarray of integers
 * @subarr: A subarray to sort
 * @buff: Buffer to store the sorted subarray
 * @front: Front index of the array
 * @mid: Middle index of the array
 * @back: Back index of the array
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t m, n, o = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (m = front, n = mid; m < mid && n < back; o++)
		buff[o] = (subarr[m] < subarr[n]) ? subarr[m++] : subarr[n++];
	for (; m < mid; m++)
		buff[o++] = subarr[m];
	for (; n < back; n++)
		buff[o++] = subarr[n];
	for (m = front, o = 0; m < back; m++)
		subarr[m] = buff[o++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - A function to implement the merge
 *     sort algorithm through recursion
 * @subarr: Subarray of an array of integers to sort
 * @buff: A buffer to store the sorted result
 * @front: Front index of the subarray
 * @back: Back index of the subarray
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - a function that sorts an array of integers
 *    in ascending order using the Merge sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: Implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *store;

	if (array == NULL || size < 2)
		return;

	store = malloc(sizeof(int) * size);
	if (store == NULL)
		return;

	merge_sort_recursive(array, store, 0, size);

	free(store);
}
