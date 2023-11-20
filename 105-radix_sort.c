#include "sort.h"
/**
 * find_max - function to find the maximum no in an array
 * @array: array with integers
 * @size: size of array
 * Return: max number
 */
int find_max(const int *array, size_t size)
{
	int max;
	size_t i;

	if (array == NULL || size == 0)
		return (0);
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort -  function that sorts an array of integers
 * @array: array with integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, digit, *countArr, *sortedArr, j;
	size_t m;

	if (!array || size < 2)
		return;
	max = find_max(array, size);
	for (exp = 1; exp <= max; exp *= 10)
	{
		countArr = malloc(sizeof(int) * 10);
		if (countArr == NULL)
			return;
		for (m = 0; m < 10; m++)
			countArr[m] = 0;
		for (m = 0; m < size; m++)
		{
			digit = (array[m] / exp) % 10;
			countArr[digit]++;
		}
		for (m = 1; m < 10; m++)
			countArr[m] += countArr[m - 1];
		sortedArr = malloc(sizeof(int) * size);
		if (sortedArr == NULL)
		{
			free(countArr);
			return;
		}
		for (j = size - 1; j >= 0; j--)
		{
			digit = (array[j] / exp) % 10;
			sortedArr[countArr[digit] - 1] = array[j];
			countArr[digit]--;
		}
		for (m = 0; m < size; m++)
			array[m] = sortedArr[m];
		print_array(array, size);
		free(countArr);
		free(sortedArr);
	}
}
