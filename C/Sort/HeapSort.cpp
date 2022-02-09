#include<stdio.h>

void Swap(int *a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MaxHeapity(int A[], int s, int e) {
	int father = s;
	int son = 2 * father + 1;
	if (son <= e) {
		if (son + 1 <= e && A[son + 1] > A[son])
			son++;
		if (A[father] < A[son])
			Swap(&A[son], &A[father]);
	}
}

int* HeapSort(int A[], int len) {
	if (len > 1) {
		for (int i = len / 2 - 1; i >= 0; i--) {
			MaxHeapity(A, i, len - 1);
		}
		Swap(&A[0], &A[len - 1]);
		HeapSort(A, len - 1);
	}
	return A;
}