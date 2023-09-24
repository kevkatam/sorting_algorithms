#include "sort.h"
/**
 * s_sort - helper function for shell sort algorithm
 * @a: input array
 * @size: size of the array
 * @gap: gap
 * Return: no return
 */
void s_sort(int *a, int size, int gap)
{
	int temp, i, j;

	for (i = 0; i + gap < size; i++)
	{
		for (j = i + gap; (j - gap) >= 0; j = j - gap)
		{
			if (a[j] < a[j - gap])
			{
				temp = a[j];
				a[j] = a[j - gap];
				a[j - gap] = temp;
			}
		}
	}
	print_array(a, size);
}
/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 *  sort algorithm, using the Knuth sequence
 *  @array: array of integers
 *  @size: size of the array
 *  Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = (gap * 3) + 1;
	while ((gap = (gap - 1) / 3) > 0)
		s_sort(array, size, gap);
}
