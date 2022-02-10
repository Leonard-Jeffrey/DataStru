#include"Sort.h"

int* QuickSort(int d[], int left, int right) {
	int len = right - left + 1;
	if (len < 2)
		return d;
	int cpy_l = left, cpy_r = right;
	int pivot = d[left];
	while (left < right) {
		while (left < right && temp < d[right])
			right--;
		d[left] = d[right];
		while (left < right && d[left] <= temp)
			left++;
		d[right] = d[left];
	}
	d[left] = pivot;
	int pos = left;
	QuickSort(d, cpy_l, pos-1);
	QuickSort(d, pos + 1, cpy_r);
	return d;
}