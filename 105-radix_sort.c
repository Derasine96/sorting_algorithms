#include "sort.h"

void radix_sort(int *array, size_t size)
{
	int max, exp, digit, *countArr, *sortedArr, j;
	size_t m;

	if (!array || size < 2)
		return;
	max = array[0];
	for (m = 1; m < size; m++)
	{
		if (max < array[m])
			max = array[m];
	}
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
