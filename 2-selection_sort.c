#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 *  using the Selection sort algorithm
 *  @array: array of integers
 *  @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_indx;

	for (i = 0; i < size - 1; i++)
	{
		min_indx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_indx])
				min_indx = j;
		}
		if (min_indx != i)
		{
			swap(&array[i], &array[min_indx]);
			print_array(array, size);
		}
	}
}
