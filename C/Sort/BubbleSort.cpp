#include"Sort.h"

int* BubbleSort(int d[], int len) {
	int i, j, temp;
	//int len = (int)sizeof(d) / sizeof(*d); //����ĳ��ȱ����ڲ����и�������ϰ��������
	if (len < 2)
		return d;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (d[j] > d[j + 1]) {
				temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}
	return d;
}