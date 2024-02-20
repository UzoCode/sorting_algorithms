#include "sort.h"

void swaps_ints(int *a, int *b);
int lomuto_partitions(int *array, size_t size, int left, int right);
void lomuto_sorts(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partitions - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: final partition index.
 */
int lomuto_partitions(int *array, size_t size, int left, int right)
{
	int *pivots, up, down;

	pivots = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivots)
		{
			if (up < down)
			{
				swaps_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivots)
	{
		swaps_ints(array + up, pivots);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sorts - Implement the quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sorts(int *array, size_t size, int left, int right)
{
	int parts;

	if (right - left > 0)
	{
		parts = lomuto_partitions(array, size, left, right);
		lomuto_sorts(array, size, left, parts - 1);
		lomuto_sorts(array, size, parts + 1, right);
	}
}

/**
 * quick_sort - Sorts array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Uses the Lomuto partitions scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sorts(array, size, 0, size - 1);
}
