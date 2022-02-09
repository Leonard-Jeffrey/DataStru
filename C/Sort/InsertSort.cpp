#include"sort.h"

int* InsertSort(int d[], int len) {
	int i, j, key;
	//int len = sizeof(d) / sizeof(d[0]);
	if (len < 2)
		return d;
	for (i = 1; i < len; i++) {
		//Find
		int temp = d[i];
		for (key = i - 1;key >= 0 && d[key] > temp;key--) {
			d[key+1] = d[key];
		}
		//Store(d[key+1], d[i])
		d[key + 1] = temp;
	}
	return d;
}