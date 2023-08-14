#include "sort.h"

/**
 * partition - partitions array
 * @array: array
 * @low: low
 * @high: high
 * @size: the size
 *
 * Return: index
 */

int partition(int *array, size_t size, int low, int high)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[high];
	i = low;

	for (j = low; j < high; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[high];
	array[high] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_rec - uses quicksort process
 * @array: array
 * @size: size of array
 * @low: low
 * @high: high
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
        int p = 0;

        if (low < high)
        {
                p = partition(array, low, high, size);
                quick_sort_rec(array, low, p - 1, size);
                quick_sort_rec(array, p + 1, high, size);
        }
}

/**
 * quicksort - quicksort
 * @array: array
 * @size: the size
 *
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
