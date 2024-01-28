#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
*/

void selection_sort(int *array, size_t size)
{
	size_t j, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (j = 0; j < size; j++)
	{
		tmp = j;
		flag = 0;
		for (index = j + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		swap = array[j];
		array[j] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}

