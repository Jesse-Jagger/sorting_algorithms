#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t k, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (k = 0; k < len - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap_ints(array + k, array + k + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
