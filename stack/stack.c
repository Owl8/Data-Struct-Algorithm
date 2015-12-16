#include <stdio.h>
#include <stdlib.h>

struct stackData_{
	struct stackData_* before;
	int data;
};
typedef struct stackData_ stackData;

void initStack(stackData**);
void push(stackData**, int); 
int pop(stackData**);
void printStack(stackData**);
void deleteStack(stackData**);

int main(void) {
	int endFlag;
	stackData stack;
	stackData* pstack = &stack;
	initStack(&pstack);
	puts("Input i, d, m, p or q.");
	for(endFlag = 0;!endFlag;) {
		int pushData;
		int popNum;
		int i;
		char cmd;
		do {
			cmd = getchar();
		} while (cmd == '\n');
		switch(cmd) {
			case 'i':
				scanf("%d", &pushData);
				push(&pstack, pushData);
				break;
			case 'd':
				pop(&pstack);
				break;
			case 'm':
				scanf("%d", &popNum);
				for (i = 0; i < popNum; ++i) {
					if (pstack->before == NULL) {
						pop(&pstack);
						break;
					}
					pop(&pstack);
				}
				break;
			case 'p':
				printStack(&pstack);
				putchar('\n');
				break;
			case 'q':
				deleteStack(&pstack);
				endFlag = 1;
				break;
			default:
				puts("Input i, d, m, p or q.");
		}
	}
	return 0;
}

void initStack(stackData** stack) {
	(*stack)->before = NULL;
}

void push(stackData** stack, int pushData) {
	stackData* newStack = (stackData*)malloc(sizeof(stackData));
	newStack->before = *stack;
	newStack->data = pushData;
	*stack = newStack;
}

int pop(stackData** stack) {
	int ret = (*stack)->data;
	stackData* beforeStack = (*stack)->before;
	if (beforeStack == NULL) {
		puts("Stack is empty.");
		return 0;
	}
	free(*stack);
	*stack = beforeStack;
	return ret;
}

void printStack(stackData** stack) {
	if ((*stack)->before != NULL) {
		printf("%d ", (*stack)->data);
		printStack(&((*stack)->before));
	}
}

void deleteStack(stackData** stack) {
	if ((*stack)->before != NULL) {
		stackData* beforeStack = (*stack)->before;
		free(*stack);
		deleteStack(&beforeStack);
	}
}
