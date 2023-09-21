#include "sort.h"
/**
 * swap - swaps two values
 * @i: first value
 * @j: second value
 * Return: no return
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order using
 *  the Bubble sort algorithm
 *  @array: array of integers
 *  @size: size of the array
 *  Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int _swap;

	for (j = size, _swap = 1; j > 0 && _swap; j--)
	{
		_swap = 0;
		for (i = 0; i < j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				print_array(array, size);
				_swap = 1;
			}
		}
	}
}
