#include <stdio.h>
#include <stdlib.h>

#define N 1000000

#define M (N+1)

void init(int A[], int seed)
{
	int i;

	srand( (unsigned int) seed );

	for (i=1; i<M; i++) {
		A[i] = rand();
	}
}

void shift(int* A, int n, int i) {
	int j, k = i, tmp;
	while (j != k) {
		j = k;
		if (2 * j <= n && A[2 * j] > A[k]) {
			k = 2 * j;
		}
		if (2 * j + 1 <= n && A[2 * j + 1] > A[k]) {
			k = 2 * j + 1;
		}
		tmp = A[j];
		A[j] = A[k];
		A[k] = tmp;
	}
}

void makeHeap(int* A, int n) {
	int i;
	for (i = n / 2; i >= 1; --i) {
		shift(A, n, i);
	}
}

void heapSort(int* A, int n) {
	int i, tmp;
	makeHeap(A, n);
	for (i = n; i >= 2; --i) {
		tmp = A[1];
		A[1] = A[i];
		A[i] = tmp;
		shift(A, i - 1, 1);
	}
}

int main(void) {
	int seed;
	int data[M] = {};
	printf("seed:");
	scanf("%d", &seed);
	init(data, seed);

	heapSort(data, N);
	printf("%d\n", data[500000]);

	return 0;
}
