#include"Sort.h"
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* SelectSort(int d[], int len) {
	//int len = sizeof(d) / sizeof(d[0]);
	if (len < 2)
		return d;
	for (int i = 0; i < len - 1;i++) {
		int min = i;
		for (j = i + 1; j < len; j++) {
			if (d[min] > d[j])
				min = j;
		}
		
		if(min != i){
			swap(&d[min],&d[i]);
		}
	}
	return d;
}
