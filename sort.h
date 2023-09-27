#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *i, int *j);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void q_sort(int *a, int low, int high, int size);
void s_sort(int *a, int size, int gap);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_list(listint_t **p1, listint_t **p2, int n);
void increase_sort(listint_t **p, listint_t **lim, listint_t **list);
void decrease_sort(listint_t **p, listint_t **lim, listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void printdata(char *m, int *arr, int f, int t);
void merge(int *arr, int low, int mid, int high, int *buf);
void m_sort(int *arr, int low, int high, int *buff);

#endif
