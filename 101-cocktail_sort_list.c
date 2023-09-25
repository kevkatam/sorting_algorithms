#include "sort.h"
/**
 * swap_list - swaps two pointers
 * @p1: first pointer
 * @p2: second pointer
 * @n: 0 for increase and 1 for decrease
 * Return: no return
 */
void swap_list(listint_t **p1, listint_t **p2, int n)
{
	listint_t *cur, *temp;

	cur = *p1;
	temp = *p2;

	cur->next = temp->next;
	temp->prev = cur->prev;

	if (temp->next)
		temp->next->prev = cur;
	if (cur->prev)
		cur->prev->next = temp;

	cur->prev = temp;
	temp->next = cur;

	if (n == 0)
		*p1 = temp;
	else
		*p2 = cur;
}
/**
 * increase_sort - moves bigger numbers to the end
 * @p: pointer to the bigger number
 * @lim: limit of the list
 * @list: list of the integers
 * Return: no return
 */
void increase_sort(listint_t **p, listint_t **lim, listint_t **list)
{
	listint_t *cur;

	cur = *p;

	while (cur != *lim && cur->next != *lim)
	{
		if (cur->n > cur->next->n)
		{
			swap_list(&cur, &(cur->next), 0);
			if (cur->prev == NULL)
				*list = cur;
			print_list(*list);
		}
		cur = cur->next;
	}
	*lim = cur;
	*p = cur;
}
/**
 * decrease_sort - moves smalller numbers to the start
 * @p: pointer to the smaller number
 * @lim: limit of the list
 * @list: list of integers
 * Return: no return
 */
void decrease_sort(listint_t **p, listint_t **lim, listint_t **list)
{
	listint_t *cur;

	cur = *p;

	while (cur != *lim && cur->prev != *lim)
	{
		if (cur->n < cur->prev->n)
		{
			swap_list(&(cur->prev), &cur, 1);
			if (cur->prev->prev == NULL)
				*list = cur->prev;
			print_list(*list);
		}
		cur = cur->prev;
	}
	*lim = cur;
	*p = cur;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *  order using the Cocktail shaker sort algorithm
 *  @list: doubly linked list of integers
 *  Return: no return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	listint_t *lim_1, *lim_2;

	if (list == NULL && *list == NULL)
		return;
	lim_1 = lim_2 = NULL;

	p = *list;
	do {
		increase_sort(&p, &lim_1, list);
		decrease_sort(&p, &lim_2, list);
	} while (lim_1 != lim_2);
}
