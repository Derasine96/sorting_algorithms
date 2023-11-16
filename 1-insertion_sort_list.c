#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @first_node: pointer to the first node
 * @second_node: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t **first_node,
		listint_t **second_node)
{
	listint_t *first = (*first_node)->prev;
	listint_t *second = (*second_node)->next;

	if (first != NULL)
		first->next = *second_node;
	else
		*list = *second_node;
	(*second_node)->prev = first;
	(*second_node)->next = *first_node;
	(*first_node)->prev = *second_node;
	(*first_node)->next = second;
	if (second != NULL)
		second->prev = *first_node;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in asc. order
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *insertion;

	if (!list || !(*list) || !((*list)->next))
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		insertion = current->prev;
		temp = current;

		while (insertion != NULL && temp->n < insertion->n)
		{
			swap_nodes(list, &insertion, &temp);
			print_list(*list);
			insertion = temp->prev;
		}

		current = current->next;
	}
}
