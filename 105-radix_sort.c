#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - A function to get the maximum value in an array of integers
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum integer in the array
 */
int get_max(int *array, int size)
{
	int highest, n;

	for (highest = array[0], n = 1; n < size; n++)
	{
		if (array[n] > highest)
			highest = array[n];
	}

	return (highest);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * @array: Array of integers
 * @size: Size of the array
 * @sig: Significant digit to sort on
 * @buff: A buffer to store the result
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t n;

	for (n = 0; n < size; n++)
		count[(array[n] / sig) % 10] += 1;

	for (n = 0; n < 10; n++)
		count[n] += count[n - 1];

	for (n = size - 1; (int)n >= 0; n--)
	{
		buff[count[(array[n] / sig) % 10] - 1] = array[n];
		count[(array[n] / sig) % 10] -= 1;
	}

	for (n = 0; n < size; n++)
		array[n] = buff[n];
}

/**
 * radix_sort - a function that sorts an array of integers
 *     in ascending order using the Radix sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: Implements the LSD radix sort algorithm and prints
 * the array after each significant you increase
 */
void radix_sort(int *array, size_t size)
{
	int highest, val, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	highest = get_max(array, size);
	for (val = 1; highest / val > 0; val *= 10)
	{
		radix_counting_sort(array, size, val, buff);
		print_array(array, size);
	}

	free(buff);
}
