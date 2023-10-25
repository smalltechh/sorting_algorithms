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
 * selection_sort -  A function that sorts an array of integers
 *   in ascending order using the Selection sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *select;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		select = array + a;
		for (b = a + 1; b < size; b++)
			select = (array[b] < *select) ? (array + b) : select;

		if ((array + a) != select)
		{
			swap_ints(array + a, select);
			print_array(array, size);
		}
	}
}
