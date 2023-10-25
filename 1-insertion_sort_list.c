#include "sort.h"

/**
 * swap_nodes - A function to swap two nodes in
 *       a listint_t doubly-linked list
 * @h: Head pointer to the doubly-linked list
 * @p1: First node to swap
 * @p2: Second node to swap
 *
 */
void swap_nodes(listint_t **h, listint_t **p1, listint_t *p2)
{
	(*p1)->next = p2->next;
	if (p2->next != NULL)
		p2->next->prev = *p1;
	p2->prev = (*p1)->prev;
	p2->next = *p1;
	if ((*p1)->prev != NULL)
		(*p1)->prev->next = p2;
	else
		*h = p2;
	(*p1)->prev = p2;
	*p1 = p2->prev;
}

/**
 * insertion_sort_list - A function that sorts a doubly linked list
 *     of integers in ascending order
 * @list: Head of a doubly-linked list
 *
 * Description: Prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *repeat, *input, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (repeat = (*list)->next; repeat != NULL; repeat = tmp)
	{
		tmp = repeat->next;
		input = repeat->prev;
		while (input != NULL && repeat->n < input->n)
		{
			swap_nodes(list, &input, repeat);
			print_list((const listint_t *)*list);
		}
	}
}
