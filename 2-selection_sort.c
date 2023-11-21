#include "sort.h"

/**
 * swap - swaps array elements
 * @a: first int
 * @b: second int to be swapped
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array using selection sort
 * @array: the array to be sorted
 * @size: array size
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i; /*set current element as min val*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min) /*swaps only when necessary*/
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}		
