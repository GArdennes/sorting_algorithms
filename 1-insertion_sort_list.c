#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 * @list: linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_list = NULL;
	listint_t *current = *list;
	listint_t *next, *temp;

	if (!list || !*list)
		return;

	while (current != NULL)
	{
		next = current->next;
		if (sorted_list == NULL || current->n < sorted_list->n)
		{
			current->next = sorted_list;
			if (sorted_list != NULL)
				sorted_list->prev = current;
			sorted_list = current;
		}
		else
		{
			temp = sorted_list;
			while (temp != NULL && temp->n < current->n)
				temp = temp->next;
			current->prev = temp->prev;
			current->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = current;
			temp->prev = current;
			if (current->prev == NULL)
				sorted_list = current;
			print_list(*list);
		}
		current = next;
	}
	/*list = sorted_list;*/
}
