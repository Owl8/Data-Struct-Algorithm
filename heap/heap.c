#include <stdio.h>

#define MAX_INDEX (10)

void initHeap(int*);
void insertHeap(int*, int);

int main(void) {
	int heap[MAX_INDEX] = {};
	int i;
	char cmd;
	for (i = 0; i < 7; heap[i] = ++i);
	puts("Input i, d, m, p or q.");
	for (cmd = 0; cmd != 'q';) {
		do {
			cmd = getchar();
		} while(cmd == '\n');
		while (cmd) {
		}
	}
	return 0;
}




