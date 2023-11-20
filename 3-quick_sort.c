#include "sort.h"

int lomuto(int *, int, int, size_t);
void sorter(int *, int, int, size_t);
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
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorter(array, 0, size - 1, size);
}

/**
 * lomuto - partition function
 * @array: array
 * @low: lower
 * @high: higher
 * @size: array's size
 * Return: pivot
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = low;
	int pivot = array[high];

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sorter - does the actual sorting
 * @array: given array
 * @low: lower
 * @high:higher
 * @size: array's size
 * Return: void
 */
void sorter(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto(array, low, high, size);
		sorter(array, low, pivot - 1, size);
		sorter(array, pivot + 1, high, size);
	}
}
