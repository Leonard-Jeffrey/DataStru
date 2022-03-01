#include"sort.h"

int* InsertSort(int d[], int len) {
	//int len = sizeof(d) / sizeof(d[0]);
	if (len < 2)
		return d;
	for (int i = 1; i < len; i++) {
		//Find
		int flag = d[i];
		int j;
		for (j = i - 1;j >= 0 && d[j] > temp;j--) {
			d[j+1] = d[j];
		}
		//Store(d[j+1], d[i])
		d[j + 1] = temp;
	}
	return d;
}
