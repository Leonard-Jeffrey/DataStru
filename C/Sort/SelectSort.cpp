#include"Sort.h"

int* SelectSort(int d[], int len) {
	int i, j, min, temp;
	//int len = sizeof(d) / sizeof(d[0]);
	if (len < 2)
		return d;
	for (i = 0; i < len - 1;i++) {
		min = i;
		for (j = i + 1; j < len; j++) {
			if (d[min] > d[j])
				min = j;
		}
		//Swap(d[temp],d[i])
		temp = d[min];
		d[min] = d[i];
		d[i] = temp;
	}
	return d;
}