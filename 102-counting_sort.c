#include "sort.h"

/**
 * get_max -  A function to get the maximum value
 *       in an array of integers
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum integer in the array
 */
int get_max(int *array, int size)
{
	int top, m;

	for (top = array[0], m = 1; m < size; m++)
	{
		if (array[m] > top)
			top = array[m];
	}

	return (top);
}

/**
 * counting_sort -  A function that sorts an array of integers
 *      in ascending order using the Counting sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: Prints the counting array once it is set up
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, top, m;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	top = get_max(array, size);
	count = malloc(sizeof(int) * (top + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (m = 0; m < (top + 1); m++)
		count[m] = 0;
	for (m = 0; m < (int)size; m++)
		count[array[m]] += 1;
	for (m = 0; m < (top + 1); m++)
		count[m] += count[m - 1];
	print_array(count, top + 1);

	for (m = 0; m < (int)size; m++)
	{
		sorted[count[array[m]] - 1] = array[m];
		count[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = sorted[m];

	free(sorted);
	free(count);
}
