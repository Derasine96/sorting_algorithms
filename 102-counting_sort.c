#include "sort.h"

/**
 * counting_sort - sorting algorithm using counting sort
 * @array: array with integers
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int j, max = 0;
	int *countArray, *sortedArray;
	size_t countArraySize, k;

	for (k = 0; k < size; k++)
	{
		if (max < array[k])
			max = array[k];
	}
	countArraySize = max + 1;
	countArray = malloc(sizeof(int) * countArraySize);
	if (countArray == NULL)
		return;
	for (k = 0; k < countArraySize; k++)
		countArray[k] = 0;
	for (k = 0; k < size; k++)
		countArray[array[k]]++;
	for (k = 0; k < countArraySize; k++)
		countArray[k] = countArray[k - 1] + countArray[k];
	print_array(countArray, countArraySize);
	sortedArray = malloc(sizeof(int) * size);
	if (sortedArray == NULL)
	{
		free(countArray);
		return;
	}
	for (j = size - 1; j >= 0; j--)
	{
		sortedArray[countArray[array[j]] - 1] = array[j];
		countArray[array[j]]--;
	}
	for (k = 0; k < size; k++)
	{
		array[k] = sortedArray[k];
	}
	free(countArray);
	free(sortedArray);
}
