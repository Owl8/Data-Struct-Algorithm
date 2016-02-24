#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
	int data;
	struct node_* left;
	struct node_* right;
} node;

int search(node* root, node** vertex, int data) {
	if (root == NULL) {
		return 0;
	}
   	if (data == root->data) {
		if (vertex != NULL) {
			*vertex = root;
		}
		return 1;
	}
	if (vertex != NULL) {
		*vertex = root;
	}
	if (data < root->data) {
		return search(root->left, vertex, data);
	} else {
		return search(root->right, vertex, data);
	}
}

node* nodeNew(int data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void insert(node** proot, int data) {
	node* vertex;
	if (*proot == NULL) {
		*proot = nodeNew(data);
		return;
	}
	if (search(*proot, &vertex, data)) {
		puts("データが存在します.");
	} else {
		if (data < vertex->data) {
			vertex->left = nodeNew(data);
		} else { 
			vertex->right = nodeNew(data);
		}
	}
}

node* maxSearch(node* root) {
	return (root->right == NULL) ? root : maxSearch(root->right);
}

void delete(node** proot, int data) {
	node* vertex;
	node* tmp = NULL;
	if (!search(*proot, &vertex, data)) {
		puts("データが存在しません.");
		return;
	}
	if (vertex->left == NULL && vertex->right == NULL) {
		free(vertex);
	} else if (vertex->left != NULL && vertex->right == NULL) {
		tmp = vertex->left;
		free(vertex);
		vertex = tmp;
	} else if (vertex->left == NULL && vertex->right != NULL) {
		tmp = vertex->right;
		free(vertex);
		vertex = tmp;
	} else {
		node* maxNode = maxSearch(vertex->left);
		vertex->data = maxNode->data;
		if (maxNode->left != NULL) {
			tmp = maxNode->left;
		}
		free(maxNode);
		maxNode = tmp;
	}
}

void print(node* root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	printf("%d ", root->data);
	print(root->right);
}

void quit(node** proot) {
	if ((*proot)->left != NULL) {
		quit(&((*proot)->left));
	}
	if ((*proot)->right != NULL) {
		quit(&((*proot)->right));
	}
	free(*proot);
}

int main(void) {
	char cmd = '\0';
	int data;
	node* root = NULL;
	puts("i, d, s, pまたはqのいずれかを入力してください.");
	for (;cmd != 'q';) {
		scanf("%1s", &cmd);
		switch (cmd) {
		case 'i':
			scanf("%d", &data);
			insert(&root, data);
			break;
		case 'd':
			scanf("%d", &data);
			delete(&root, data);
			break;
		case 's':
			scanf("%d", &data);
			if (search(root, NULL, data)) {
				puts("データが存在します.");
			} else {
				puts("データが存在しません.");
			}
			break;
		case 'p':
			print(root);
			putchar('\n');
			break;
		case 'q':
			break;
		default:
			puts("i, d, s, pまたはqのいずれかを入力してください.");
		}
	}
	quit(&root);
	return 0;
}
