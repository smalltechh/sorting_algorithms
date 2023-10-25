#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - A function to swap two integers
 * @x: First integer to be swap
 * @y: Second integer to be swap
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers
 * @array: Array of integers
 * @size: Size of the array
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Function to Implement the quicksort
 *      algorithm through recursion
 * @array: Array of integers
 * @size: Size of the array
 * @left: Starting index of the array partition to sort
 * @right: Ending index of the array partition to sort
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int unit;

	if (right - left > 0)
	{
		unit = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, unit - 1);
		lomuto_sort(array, size, unit + 1, right);
	}
}

/**
 * quick_sort - A function that sorts an array of integers
 *     in ascending order using the Quick sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: Prints the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
