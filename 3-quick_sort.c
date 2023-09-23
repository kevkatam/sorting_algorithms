#include "sort.h"
/**
 * q_sort - helper function for quicksort alogrithm
 * @a: array of integers
 * @high: last element of the array
 * @low: first element of the array
 * @size: size of array
 * Return: no return
 */
void q_sort(int *a, int low, int high, int size)
{
	int pivot, b, i;
	int temp;

	if (low < high)
	{
		pivot = high;
		b = low;
		for (i = low; i < high; i++)
		{
			if (a[i] < a[pivot])
			{
				if (i != b)
				{
					temp = a[i];
					a[i] = a[b];
					a[b] = temp;
					print_array(a, size);
				}
				b++;
			}
		}
		if (i != b && a[b] != a[pivot])
		{
			temp = a[pivot];
			a[pivot] = a[b];
			a[b] = temp;
			print_array(a, size);
		}
		q_sort(a, low, b - 1, size);
		q_sort(a, b + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *  Quick sort algorithm
 *  @array: array of integers
 *  @size: size of array
 *  Return: no return
 */
void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}
