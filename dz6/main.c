/*
* Dmitry Panfilov
* HomeWork 6
*/
#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

/*
 * 1. ����������� ���������� ���-�������. �� ���� ������� ������� ������, �� ������ ����� ����� ��������.
 */
unsigned int crc(char* str) {
	unsigned int c = 0;
	while (*str != '\0') {
		c += *str;
		str++;
	}
	return c;
}

////////// Tree //////////
typedef int T;
typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

// ���������� ��������� ������ � ���� ��������� ������
void printTree(Node *root) {
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

// �������� ������ ����
Node* getNewNode(T value, Node* parent) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL) {
		printf("Stack Overflow");
		return NULL;
	}
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp; 
}

// ������� ����
void insertNode(Node **head, int value) {
	if (*head == NULL)
		*head = getNewNode(value, NULL);
	else if (value > (*head)->data) {
		if ((*head)->right)
			insertNode(&(*head)->right, value);
		else
			(*head)->right = getNewNode(value, *head);
	} else  {
		if ((*head)->left)
			insertNode(&(*head)->left, value);
		else
			(*head)->left = getNewNode(value, *head);
	}
}

// ����� 1
void goRootLeftRight(Node* root) {
	if (root) {
		printf("%d ", root->data);
		goRootLeftRight(root->left);
		goRootLeftRight(root->right);
	}
}

// ����� 2
void goLeftRootRight(Node* root) {
	if (root) {
		goLeftRootRight(root->left);
		printf("%d ", root->data);
		goLeftRootRight(root->right);
	}
}

// ����� 3
void goLeftRightRoot(Node* root) {
	if (root) {
		goLeftRightRoot(root->left);
		goLeftRightRoot(root->right);
		printf("%d ", root->data);
	}
}

// ����� ��������, -1 �� ������, ����� ��������
T searchTree(Node* root, T value) {
	if (root == NULL)
		return -1;
	else if (root->data == value)
		return value;
	else if (root->data > value)
		return searchTree(root->left, value);
	else
		return searchTree(root->right, value);
}

/*
* Main function
*/
int main(int argc, char* argv[]) {
	#define SIZE 10
	int arr[SIZE] = {6,8,7,3,9,10,0,4,1,2};
	Node* tree = NULL;
	int i;

    setlocale(LC_ALL, "Russian");
    printf("Dmitry Panfilov �������� ������ �6\n");
    
    printf("\n������� �1: CRC.\n");
    printf("\"test string\" = %d\n", crc("test string"));

	printf("\n������� �2: ������ ������, ������ � ����� ��������.\n");
	printf("arr = ");

	for (i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
		insertNode(&tree, arr[i]);
	}
	printf("\ntree = ");
	printTree(tree);
	printf("\n��� = ");
	goRootLeftRight(tree);
	printf("\n��� = ");
	goLeftRootRight(tree);
	printf("\n��� = ");
	goLeftRightRoot(tree);
	printf("\nSearch 4 = %d", searchTree(tree, 4));
	printf("\nSearch 5 = %d", searchTree(tree, 5));

    getch();
    return 0;
}