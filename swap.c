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
