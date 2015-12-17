#include <stdio.h>

#define MAX_INDEX (11)

void downHeap(int*, int, int);
void upHeap(int*, int);
void putHeap(int*, int*, int);
int getHeap(int*, int*);
void printHeap(int*, int);

int main(void) {
	int heap[MAX_INDEX] = {};
	int size = 7;
	int i;
	char cmd;
	int putData;
	for (i = 1; i <= size; i++)
		heap[i] = i;
	for (i = size; --i; )
		upHeap(heap, i + 1);
	puts("Input i, d, m, p or q.");
	for (cmd = 0; cmd != 'q';) {
		do {
			cmd = getchar();
		} while(cmd == '\n');
		switch (cmd) {
		case 'i':
			scanf("%d", &putData);
			putHeap(heap, &size, putData);
			break;
		case 'd':
			getHeap(heap, &size);
			break;
		case 'p':
			printHeap(heap, size);
			break;
		case 'q':
			break;
		default:
			puts("Input i, d, m, p or q.");
		}
	}
	return 0;
}

void downHeap(int* heap, int size, int index) {
	int v = heap[index], i = index * 2;
	for (;i <= size;) {
		if (i < size && heap[i] < heap[i + 1]) 
			++i;
		if (heap[i] <= v)
			break;
		heap[index] = heap[i];
		index = i;
		i *= 2;
	}
	heap[index] = v;
}

void upHeap(int* heap, int index) {
	int v = heap[index], i = index / 2;
	for (; i >= 1; i /= 2) {
		if (heap[i] >= v) 
			break;
		heap[index] = heap[i];
		index = i;
	}
	heap[index] = v;
}

void putHeap(int* heap, int* size, int data) {
	if (*size + 1 >= MAX_INDEX) {
		puts("Heap is full.");
		return;
	}
	++(*size);
	heap[*size] = data;
	upHeap(heap, *size);
}

int getHeap(int* heap, int* size) {
	if (*size <= 0) {
		puts("Heap is empty.");
		return 0;
	}
	int ret = heap[0];
	heap[0] = heap[*size];
	--(*size);
	downHeap(heap, *size, 0);
	return ret;
}
	
void printHeap(int* heap, int size) {
	int i;
	for (i = 1; i <= size; printf("%d ", heap[i++]));
	putchar('\n');
}
