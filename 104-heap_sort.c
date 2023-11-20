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
 * swap_root_nodes - A function that swap the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @high: The higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void swap_root_nodes(int *array, size_t root, size_t high, size_t size)
{
	size_t low = 0, mid = 0, temp = 0;

	while ((low = (2 * root + 1)) <= high)
	{
		temp = root;
		mid = low + 1;
		if (array[temp] < array[low])
			temp = low;
		if (mid <= high && array[temp] < array[mid])
			temp = mid;
		if (temp == root)
			return;
		swap(&array[root], &array[temp]);
		print_array(array, size);
		root = temp;
	}
}

/**
 * heap_sort - A function that sorts an array using heap algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t high = 0, gap = 0;

	if (array == NULL || size < 2)
		return;

	for (gap = (size - 2) / 2; 1; gap--)
	{
		swap_root_nodes(array, gap, size - 1, size);
		if (gap == 0)
			break;
	}

	high = size - 1;
	while (high > 0)
	{
		swap(&array[high], &array[0]);
		print_array(array, size);
		high--;
		swap_root_nodes(array, 0, high, size);
	}
}
