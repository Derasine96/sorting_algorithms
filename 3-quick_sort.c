#include "sort.h"

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
	int pivot = array[high], temp = 0;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
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
