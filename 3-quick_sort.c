#include "sort.h"

/**
 * quick_sort - quick sort
 * @array: array
 * @size: size
 *
 */
void quick_sort(int *array, size_t size)
{
	int piv, high, low;

	if (size < 2)
		return;
	high = (int)size - 1;
	low = 0;
	if (low < high)
	{
		piv = partition(array, low, high, size);
		quicksort(array, low, piv - 1, size);
		quicksort(array, piv + 1, high, size);
	}
}

/**
 * quicksort - sorts parts of array
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int piv;

	if (low < high)
	{
		piv = partition(array, low, high, size);
		quicksort(array, low, piv - 1, size);
		quicksort(array, piv + 1, high, size);
	}
}

/**
 * e_swap - swap elements of array
 * @array_1: first element
 * @array_2: second element
 *
 */
void e_swap(int *array_1, int *array_2)
{
	int temp;

	temp = *array_1;
	*array_1 = *array_2;
	*array_2 = temp;
}


/**
 * partition - makes partition
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 *
 * Return: index
 *
 */
int partition(int *array, int low, int high, size_t size)
{
	int index, pivot, index2;

	pivot = array[high];
	index = (low - 1);
	for (index2 = low; index2 <= high - 1; index2++)
	{
		if (array[index2] <= pivot)
		{
			index++;
			if (index != index2)
			{
				e_swap(&array[index], &array[index2]);
				print_array(array, size);
			}
		}
	}
	if (index + 1 != high)
	{
		e_swap(&array[index + 1], &array[high]);
		print_array(array, size);
	}
	return (index + 1);
}

/**
 * highandlow - the high or low value based on request
 * @array: array
 * @size: size
 * @h_l: flag
 *
 * Return: high or low value
 */
int highandlow(int *array, size_t size, int h_l)
{
	int value = array[0], index = 1, temp_size = 0;
	int ar_index = 0;

	temp_size = (int)size;
	for (index = 1; index < temp_size; index++)
	{
		if (h_l == 0)
		{
			if (array[index] < value)
			{
				value = array[index];
				ar_index = index;
			}
		}
		else
		{
			if (array[index] > value)
			{
				value = array[index];
				ar_index = index;
			}
		}
		index++;
	}
	return (ar_index);
}
