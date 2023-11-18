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
 * @size: array length
 * @pivot_index: the index of the pivot
 * Return: the new pos. of the pivot element after partitioning
 */
size_t lomuto(int *array, size_t size, int pivot_index)
{
	int pivot, i, j, *large = NULL, *small = NULL;

	pivot = array[pivot_index];

	for (i = 0; i < pivot_index; i++)
	{
		if (array[i] > pivot)
		{
			large = &array[i];
			break;
		}
	}
	if (pivot_index == 0)
		return (size);
	if (large == NULL)
		return (lomuto(array, size, pivot_index - 1));
	for (j = pivot_index - 1; j >= 0; j--)
	{
		if (array[j] < pivot)
		{
			small = &array[j];
			break;
		}
	}
	if (small == NULL || i > j)
	{
		swap(&array[i], &array[pivot_index]);
		print_array(array, size);
		return (i);
	}
	else
	{
		swap(&array[i], &array[j]);
		print_array(array, size);
		return (lomuto(array, size, pivot_index));
	}
}

/**
 * quick_sort - sorts an array using Quick Sort algorithm
 * @array: pointer to an array of integers
 * @size: size of integers
 */
void quick_sort(int *array, size_t size)
{
	size_t res;

	if (!array || size < 2)
		return;
	res = lomuto(array, size, size - 1);
	if (res != size)
		quick_sort(array, size);
}
