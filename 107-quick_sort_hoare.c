#include "sort.h"

int hoare_partition(int *, int, int, size_t);
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
 * quick_sort_hoare - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorter(array, 0, size - 1, size);
}

/**
 * hoare_partition - partition function
 * @array: array
 * @low: The starting index of the subset to order
 * @high: The ending index of the subset to order
 * @size: array's size
 * Return: final partition index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, above, below;

	pivot = array[high];
	for (above = low - 1, below = high + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(&array[above], &array[below]);
			print_array(array, size);
		}
	}

	return (above);
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
		pivot = hoare_partition(array, low, high, size);
		sorter(array, low, pivot - 1, size);
		sorter(array, pivot, high, size);
	}
}
