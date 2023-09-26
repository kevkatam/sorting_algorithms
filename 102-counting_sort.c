#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using the
 *  Counting sort algorithm
 *  @array: array of integers
 *  @size: size of the array
 *  Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count, *output;

	if (size < 2)
		return;

	for (max = i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i < max + 1; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < max + 1; i++)
		count[i] += count[i - 1];
	
	print_array(count, max + 1);

	output = malloc(sizeof(int) * (size + 1));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
	free(count);
	free(output);
}
