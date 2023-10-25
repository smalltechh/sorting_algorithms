#include "sort.h"

/**
 * swap_ints - A function to swap two integers
 * @x: First integer to swap
 * @y: Second integer to swap
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - A function that sorts an array of integers in ascending
 *    order using the Shell sort algorithm, using the Knuth sequence
 * @array: Array of integers
 * @size: Size of the array
 * Description: Uses the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t space, j, k;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (j = space; j < size; j++)
		{
			k = j;
			while (k >= space && array[k - space] > array[k])
			{
				swap_ints(array + k, array + (k - space));
				k -= space;
			}
		}
		print_array(array, size);
	}
}
