#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of doubly linked list
 * @node: node root to swap
 * @list: double link list head
 */
void swap_nodes(listint_t **node, listint_t **list)
{
	listint_t *temp = *node, *ahead, *behind;

	if (!(*node)->prev)
		*list = (*node)->next;
	temp = behind = *node;
	ahead = temp->next;
	temp->next = ahead->next;
	behind = temp->prev;
	temp->prev = ahead;
	ahead->next = temp;
	ahead->prev = behind;
	if (ahead->prev)
		ahead->prev->next = ahead;
	if (temp->next)
		temp->next->prev = temp;
	*node = ahead;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: head of list to be sortered (Double Linked List)
 *
 * Return: No Return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *temp;
	int a = 0, b = 0;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	head = *list;
	while (a >= 0)
	{
		while (head->next)
		{
			if (head->n > head->next->n)
			{
				temp = head;
				swap_nodes(&temp, list);
				b = 1;
				print_list(*list);
				head = temp;
			}
			head = head->next;
		}
		while (head->prev)
		{
			if (head->n < head->prev->n)
			{
				temp = head->prev;
				swap_nodes(&temp, list);
				b = 1;
				print_list(*list);
				head = temp->next;
			}
			head = head->prev;
		}
		if (a == b)
			a = -1;
		else
			b = 0;
	}
}
