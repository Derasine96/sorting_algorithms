#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (*list == NULL || node1 == NULL || node2 == NULL)
		return;
	if (*list == node1)
		*list = node2;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * @list: pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL, *current;

	if (!(*list) || !((*list)->next))
		return;
	do {
		swapped = 0;
		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		if (!swapped)
			break;
		end = current;
		swapped = 0;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
			}
			current = current->prev;
		}
		start = current->next;
	} while (swapped);
}
