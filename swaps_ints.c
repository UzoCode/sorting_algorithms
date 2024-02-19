#include "sort.h"

/**
 * swaps_ints - Swap two  given integers
 * @a: First integer
 * @b: Second integer
 */

void swaps_ints(int *a,int *b)
{
	int tmp;
	tmp = *a; 
	*a = *b;
	*b = tmp;
}
