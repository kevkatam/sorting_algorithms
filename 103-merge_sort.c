#include "sort.h"
/**
 * printdata - prints data
 * @m: message
 * @arr: array
 * @f: from
 * @t: to
 * Return: no return
 */
void printdata(char *m, int *arr, int f, int t)
{
	char *s;
	int i;

	printf("[%s]: ", m);

	s = "";
	for (i = f; i < t + 1; i++)
	{
		printf("%s%d", s, arr[i]);
		s = ", ";
	}
	printf("\n");
}
/**
 * merge - helper function for the merging sort algorithm
 * @arr: array of integers
 * @low: low index
 * @mid: middle index
 * @high: high index
 * @buf: buffer to store the merged arrays
 * Return: no return
 */
void merge(int *arr, int low, int mid, int high, int *buf)
{
	int i, l, m;

	l = i = low;
	m = mid + 1;

	printf("Merging...\n");
	printdata("left", arr, low, mid);
	printdata("right", arr, mid + 1, high);

	while (l < mid + 1 && m < high + 1)
	{
		if (arr[l] < arr[m])
		{
			buf[i] = arr[l];
			i++;
			l++;
		}
		else
		{
			buf[i] = arr[m];
			i++;
			m++;
		}
	}
	while (l < mid + 1)
	{
		buf[i] = arr[l];
		i++;
		l++;
	}
	while (m < high + 1)
	{
		buf[i] = arr[m];
		i++;
		m++;
	}
	for (i = low; i < high + 1; i++)
		arr[i] = buf[i];
	printdata("Done", arr, low, high);
}
/**
 * m_sort - helper recursive function for the merge sort algoritm
 * @arr: array of integers
 * @low: low index
 * @high: high index
 * @buff: buffer
 * Return: no return
 */
void m_sort(int *arr, int low, int high, int *buff)
{
	int midd;

	if (low < high)
	{
		midd = (low + high - 1) / 2;
		m_sort(arr, low, midd, buff);
		m_sort(arr, midd + 1, high, buff);
		merge(arr, low, midd, high, buff);
	}
}
/**
 * merge_sort -  sorts an array of integers in ascending order using the
 *  Merge sort algorithm
 *  @array: array of integers
 *  @size: size of the array
 *  Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	m_sort(array, 0, size - 1, buff);
	free(buff);
}
