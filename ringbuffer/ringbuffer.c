#include <stdio.h>

#define DataNum (6)

typedef struct {
	int data[DataNum];
	int top;
	int tail;
} ringbuffer;

void init(ringbuffer*);
void enqueue(ringbuffer*, int);
int dequeue(ringbuffer*);
void printRingBuffer(ringbuffer*);

int main(void) {
	ringbuffer rb;
	char cmd;
	init(&rb);
	puts("Input i, d, p or q.");
	for (cmd = 0; cmd != 'q'; ) {
		int enqueueData;
		do {
			cmd = getchar();
		} while(cmd == '\n');
		switch(cmd) {
		case 'i':
			scanf("%d", &enqueueData);
			enqueue(&rb, enqueueData);
			break;
		case 'd':
			dequeue(&rb);
			break;
		case 'p':
			printRingBuffer(&rb);
			break;
		case 'q':
			break;
		default:
			puts("Input i, d, p or q.");
		}
	}
	return 0;		
}

void init(ringbuffer* rb) {
	int i;
	for (i = 0; i < DataNum; ++i) {
		rb->data[i] = 0;
	}
	rb->top = rb->tail = 0;
}

void enqueue(ringbuffer* rb, int num) {
	if (rb->top == (rb->tail + 1) % DataNum) {
		puts("Queue is filled.");
		return;
	}
	rb->data[rb->tail] = num;
	rb->tail = ++(rb->tail) % DataNum;
}

int dequeue(ringbuffer *rb) {
	int ret = rb->data[rb->top];
	if (rb->top % DataNum == rb->tail) {
		puts("Queue is empty.");
		return;
	}
	rb->data[(rb->top)++] = 0;
	rb->top %= DataNum;
	return ret;
}

void printRingBuffer(ringbuffer* rb) {
	int i;
	for (i = rb->top; i != rb->tail; i = ++i % DataNum) {
		printf("%d ", rb->data[i]);
	}
	putchar('\n');
}

