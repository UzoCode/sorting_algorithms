#include "sort.h"

/**
 * swaps_ints - Swaps two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swaps_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Prints the array after every swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mins;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mins = array + i;
		for (j = i + 1; j < size; j++)
			mins = (array[j] < *mins) ? (array + j) : mins;

		if ((array + i) != mins)
		{
			swaps_ints(array + i, mins);
			print_array(array, size);
		}
	}
}
