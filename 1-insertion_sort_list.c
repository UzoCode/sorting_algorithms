#include "sort.h"

/**
 * swaps_nodes - Swaps two nodes in listint_t doubly-linked list.
 * @h: pointer to the head of the doubly-linked list.
 * @n1: pointer to the first node to swap.
 * @n2: second node to swap.
 */
void swaps_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}



/**
 * insertion_sort_list - sorts doubly linked list of
 * integers in ascending order
 * @list: pointer to the head of the doubly linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iters, *inserts, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iters = (*list)->next; iters != NULL; iters = tmp)
	{
		tmp = iters->next;
		inserts = iters->prev;
		while (inserts != NULL && iters->n < inserts->n)
		{
			swaps_nodes(list, &inserts, iters);
			print_list((const listint_t *)*list);
		}
	}
}
