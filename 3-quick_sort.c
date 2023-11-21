#include "sort.h"
/**
 * swap - swaps two values
 * @a: first value
 * @b: second value
 */
void swap(int *a, int *b)
{
	int temp = *a;

	(*a) = (*b);
	(*b) = temp;
}
/**
 * split - partitions array
 * @arr: array to partition
 * @high: highest index
 * @low: lowest index
 * Return: returns the partitioning index
 */
int split(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
/**
 * recursive_quick_sort - sorts both sides of the index
 * @array: array to be sorted
 * @size: array size
 * @high: highest index
 * @low: lowest index
 */
void recursive_quick_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int partition_index = split(array, low, high);

		print_array(array, size);

		recursive_quick_sort(array, size, low, partition_index - 1);
		recursive_quick_sort(array, size, partition_index + 1, high);
	}
}
/**
 * quick_sort - sorts array using quick sort
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	recursive_quick_sort(array, size, 0, size - 1);
}
