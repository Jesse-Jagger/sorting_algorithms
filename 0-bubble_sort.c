#include "sort.h"

/**
 * bubble_sort - sorts array lements from min to max value
 * @array: array
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{

	size_t k, index, tmp = 0;

	if (size < 2)
		return;
	for (k = 0; k < size; k++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, size);
			}
		}
}
