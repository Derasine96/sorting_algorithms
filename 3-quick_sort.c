#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto - partitions the array around a pivot element
 * @array: pointer to an array of integers
 * @small: low index for the current iteration
 * @large: high index for the current iteration
 * Return: the new pos. of the pivot element after partitioning
 */
size_t lomuto(int *array, size_t small, size_t large)
{
	int pivot, temp;
	size_t i, j;

	pivot = array[large];
	i = small;
	for (j = small; j < large; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[small];
	array[small] = array[i];
	array[i] = temp;
	print_array(array, large - small + 1);
	return (i);
}

/**
 * quick_sort - sorts an array using Quick Sort algorithm
 * @array: pointer to an array of integers
 * @size: size of integers
 */
void quick_sort(int *array, size_t size)
{
	size_t small, large, mid;

	if (size > 1)
	{
		small = 0;
		large = size - 1;
		while (small <= large)
		{
			mid = lomuto(array, small, large);
			if (mid > small)
			{
				quick_sort(array + small, mid - small);
			}
			small = mid + 1;
		}
	}
}
