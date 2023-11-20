#include "sort.h"

void merger(size_t lo, size_t mi, size_t hi, int *dest, int *src);
void partitioner(size_t lo, size_t hi, int *array, int *base);
/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *array_copy = NULL;

	if (array == NULL || size < 2)
		return;
	array_copy = malloc(sizeof(int) * size);
	if (array_copy == NULL)
		return;
	for (; i < size; i++)
		array_copy[i] = array[i];
	partitioner(0, size, array, array_copy);
	free(array_copy);
}

/**
 * merger- A function that sorts the subarrays.
 * @low: Lower index.
 * @mid: Middle index.
 * @high: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merger(size_t low, size_t mid, size_t high, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + low, mid - low);
	printf("[right]: ");
	print_array(src + mid, high - mid);
	i = low;
	j = mid;
	k = low;
	for (; k < high; k++)
	{
		if (i < mid && (j >= high || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + low, high - low);
}

/**
 * partitioner - A funtion that partitions the array recursively.
 * @low: Lower index.
 * @high: Higher index.
 * @array: The array to sort.
 * @array_copy: The copy of the array.
 * Return: Nothing.
 */
void partitioner(size_t low, size_t high, int *array, int *array_copy)
{
	size_t mid = 0;

	if (high - low < 2)
		return;
	mid = (low + high) / 2;
	partitioner(low, mid, array, array_copy);
	partitioner(mid, high, array, array_copy);
	merger(low, mid, high, array, array_copy);
	for (mid = low; mid < high; mid++)
		array_copy[mid] = array[mid];
}
