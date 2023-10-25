#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Function to swap two integers
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
 * bitonic_merge - Bitonic sequence inside an array of integers
 * @array: Array of integers
 * @size: Size of the array
 * @start: Starting index of the sequence in array to sort
 * @seq: The size of the sequence to sort
 * @flow: The directionof flow to sort
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t n, jump = seq / 2;

	if (seq > 1)
	{
		for (n = start; n < start + jump; n++)
		{
			if ((flow == UP && array[n] > array[n + jump]) ||
			    (flow == DOWN && array[n] < array[n + jump]))
				swap_ints(array + n, array + n + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - A function that convert an array of
 *    integers into a bitonic sequence
 * @array: An array of integers
 * @size:  size of the array
 * @start: Starting index of a block of the building bitonic sequence.
 * @seq: size of a block of the building bitonic sequence.
 * @flow: Direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - a function that sorts an array of integers
 *     in ascending order using the Bitonic sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: Prints array after each swap and it Only works for
 *   size = 2^k where k >= 0 (ie. size equal to powers of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
