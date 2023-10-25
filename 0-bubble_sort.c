#include "sort.h"

/**
 * swap_ints - Function to swap two integers in an array
 * @x: First integer
 * @y: Second integer
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - function that sorts an array of integers
 *   in ascending order
 * @array: An array of integers
 * @size: Size of the array
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t h, ar_len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (h = 0; h < ar_len - 1; h++)
		{
			if (array[h] > array[h + 1])
			{
				swap_ints(array + h, array + h + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		ar_len--;
	}
}
