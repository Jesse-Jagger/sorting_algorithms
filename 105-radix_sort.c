#include "sort.h"
#include <stdio.h>

/**
* getMax - A utility function to get maximum value in arr[]
* @arr: array
* @n: size of the array
* Return: array
*/

int getMax(int *arr, int n)
{
	int j, max = arr[0];

	for (j = 1; j < n; j++)
		if (arr[j] > max)
			max = arr[j];
	return (max);
}

/**
* countSort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int j;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (j = 0; j < (int)n; j++)
		count[(arr[j] / exp) % 10]++;

	/*
	* Change count[i] so that count[i] now contains actual
    * position of this digit in output[]
	*/
	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	/* Build the output array */
	for (j = n - 1; j >= 0; j--)
	{
		output[count[(arr[j] / exp) % 10] - 1] = arr[j];
		count[(arr[j] / exp) % 10]--;
	}

	/*
	* Copies the output array to arr[], so that arr[] now
    * contains sorted numbers according to current digit
	*/
	for (j = 0; j < (int)n; j++)
		arr[j] = output[j];
	/*print_array(arr, n);*/
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Finds the maximum number to know number of digits */
	int exp, maximum = 0;
	int *output = '\0'; /* output array should be n(size) */

	if (array == '\0' || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;
	/*
	* Do counting sort for every digit. Note that instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}

