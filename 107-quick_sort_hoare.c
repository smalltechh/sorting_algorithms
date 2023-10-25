#include "sort.h"

void swap_ints(int *i, int *j);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - A function to swap two integers
 * @i: First integer to swap
 * @j: Second integer to swap.
 */
void swap_ints(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * hoare_partition - Subset of an array of integers according
 *   to the hoare partition scheme
 * @array: Array of integers
 * @size: Size of the array.
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 * Return: Final partition index
 * Description: This uses the last element of the partition as the pivot
 *    and prints the array after each swap of two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, up, down;

	pivot = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Function to implement the quicksort algorithm through recursion
 * @array: Array of integers to sort
 * @size: Size of the array
 * @left: Starting index of the array partition to order
 * @right: Ending index of the array partition to order
 * Description: Uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int unit;

	if (right - left > 0)
	{
		unit = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, unit - 1);
		hoare_sort(array, size, unit, right);
	}
}

/**
 * quick_sort_hoare - a function that sorts an array of integers
 *   in ascending order using the Quick sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: This uses the Hoare partition scheme and prints
 *      the array after each swap of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
