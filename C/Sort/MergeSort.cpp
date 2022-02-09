#include"Sort.h"
#include <stdlib.h>
const int maxn = 100;
void Merge(int *A, int s1, int e1, int s2, int e2) {
	int i=s1, j=s2, index = 0;
	int temp[maxn] = {0};
	while (i <= e1 && j <= e2) {
		if (A[i] > A[j])
			temp[index++] = A[j++];
		else
			temp[index++] = A[i++];
	}
	while (i <= e1)
		temp[index++] = A[i++];
	while (j <= e2)
		temp[index++] = A[j++];
	for (int i = 0; i < index; i++) {
		A[s1 + i] = temp[i];
	}
}
//·ÇµÝ¹é
int* MergeSort(int A[], int len) {
	for (int i = 2; i/2 < len; i *= 2) {
		for (int j = 0; j < len; j += i) {
			if(j+i/2 < len)
				Merge(A,j, j+i/2-1,j+i/2,min(j + i -1, len-1));
		}
	}
	return A;
}

//µÝ¹é
int* MergeSortR(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSortR(A, left, mid);
		MergeSortR(A, mid + 1, right);
		Merge(A, left, mid, mid + 1, right);
	}
	return A;
}