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

#include "sort.h"

/**
 * selection_sort - func. that sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, min;

	if (!array || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min])
				min = b;
		}
		if (min != a)
		{
			swap(&array[min], &array[a]);
			print_array(array, size);
		}
	}
}
