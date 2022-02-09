#include"Sort.h"

//希尔排序是简单插入排序的改进版；
int* ShellSort(int d[], int len) {
	//int len = sizeof(d) / sizeof(d[0]);
	if (len < 2)
		return d;
	//Team:gap
	for (int gap = len / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < len; i++) {
			int temp = d[i];
			int key;
			for (key = i - gap; key >= 0 && d[key] > temp;key -= gap) {
				d[key + gap] = d[key];
			}
			d[key+gap] = temp;
			//key = i - gap;
			////current = i;
			////Find:key
			//while (key >= gap && d[key] > d[i]) {
			//	key -= gap;
			//}
			////Move
			//for (j = i;j > 0;j--) {
			//	d[j] = d[j - 1];
			//}
			////Store(d[key],d[i])
			//d[key] = d[i];
		}
	}
	return d;
}