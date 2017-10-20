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
    while (*str != '\0')
        c += *str++;
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

////////// ���� ������ ///////////
typedef struct {
    int id;
    char name[31];
    int age;
} Student; // ������ � ��������

typedef struct NodeStudent {
    struct NodeStudent* next;
    Student* data;
} NodeStudent; // ������� ������ ���������

typedef struct {
    NodeStudent* head;
    int size;
} StackStudents; // ���� ���������

typedef struct TreeNode {
    NodeStudent* data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode; // ������� ������ ���������

// �������� ������ ���� ������
TreeNode* getNewTreeNodeStudent(NodeStudent *value, TreeNode* parent) {
    TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
    if (tmp == NULL) {
        printf("Stack Overflow");
        return NULL;
    }
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// �������� ������ �������� ������
NodeStudent* getNewNodeStudent(NodeStudent* head, Student* data) {
    NodeStudent* tmp = (NodeStudent*)malloc(sizeof(NodeStudent));
    if (tmp == NULL) {
        printf("Stack Overflow");
        return NULL;
    }
    tmp->data = data;
    tmp->next = head;
    return tmp;

}

#define TYPE_TREE_BY_ID 0
#define TYPE_TREE_BY_AGE 1
#define TYPE_TREE_BY_NAME 2
// ������� ����
// ���������� �������� ������������ � ������ �� ����� ����
void insertNodeStudent(TreeNode **head, Student* value, int type) {
    int isRight = 0;
    if (*head == NULL) {
        *head = getNewTreeNodeStudent(getNewNodeStudent(NULL, value), NULL);
        return;
    }

    switch (type) {
        case TYPE_TREE_BY_ID:
            if (value->id == (*head)->data->data->id) {
                (*head)->data = getNewNodeStudent((*head)->data, value);
                return;
            }
            isRight = (value->id > (*head)->data->data->id);
            break;
        case TYPE_TREE_BY_AGE:
            if (value->age == (*head)->data->data->age) {
                (*head)->data = getNewNodeStudent((*head)->data, value);
                return;
            }
            isRight = (value->age > (*head)->data->data->age);
            break;
        case TYPE_TREE_BY_NAME:
            isRight = strcmp(value->name, (*head)->data->data->name);
            if (isRight == 0) {
                (*head)->data = getNewNodeStudent((*head)->data, value);
                return;
            }
            isRight = (isRight > 0);
            break;
        default:
            printf("����������� ��� ���������� ������!");
    }

    if (isRight) {
        if ((*head)->right)
            insertNodeStudent(&(*head)->right, value, type);
        else
            (*head)->right = getNewTreeNodeStudent(getNewNodeStudent(NULL, value), *head);
    } else {
        if ((*head)->left)
            insertNodeStudent(&(*head)->left, value, type);
        else
            (*head)->left = getNewTreeNodeStudent(getNewNodeStudent(NULL, value), *head);
    }
}

// ��������� ������ ������
TreeNode* getSearchTree(NodeStudent* head, int type) {
    TreeNode* tree = NULL;
    while (head) {
        insertNodeStudent(&tree, head->data, type);
        head = head->next;
    }
    return tree;
}

// ������ �������� ����
void writeDB() {
    int i = 0;
    Student student[10];
    FILE * file;
    strcpy(student[0].name, "���� ������");
    student[0].id = 6;
    student[0].age = 18;
    strcpy(student[1].name, "������� ���������");
    student[1].id = 22;
    student[1].age = 20;
    strcpy(student[2].name, "����� ��������");
    student[2].id = 11;
    student[2].age = 21;
    strcpy(student[3].name, "������� �������");
    student[3].id = 18;
    student[3].age = 23;
    strcpy(student[4].name, "���� ������");
    student[4].id = 16;
    student[4].age = 18;
    strcpy(student[5].name, "������ �������");
    student[5].id = 100;
    student[5].age = 20;
    strcpy(student[6].name, "���� ��������");
    student[6].id = 34;
    student[6].age = 24;
    strcpy(student[7].name, "���������� �����");
    student[7].id = 12;
    student[7].age = 19;
    strcpy(student[8].name, "������� ������");
    student[8].id = 7;
    student[8].age = 21;
    strcpy(student[9].name, "��������� ��������");
    student[9].id = 10;
    student[9].age = 22;

    file = fopen("students.db", "wb");
    if (file != NULL) {
        for(i=0; i< 10; i++)
            fwrite(&student[i], sizeof(Student), 1, file);
        fclose(file);
    }
}

// ���������� ��������� � ����
void pushStack(StackStudents* stack, Student* value) {
    stack->head = getNewNodeStudent(stack->head, value);
    stack->size++;
}

// ����� ��������� �� �����
void printStudents(NodeStudent* node) {
    if (node) {
        printf("%d\t%s\t%d\n", node->data->id, node->data->name, node->data->age);
        printStudents(node->next);
    }
}

// ����� ������ ������ ���������
void printTreeStudents(TreeNode* root) {
    if (root) {
        printTreeStudents(root->left);
        printf("����:\n");
        printStudents(root->data);
        printTreeStudents(root->right);
    }

}

// ����� �� �������� �� �����
NodeStudent* searchByName(TreeNode* root, char* name) {
    int result = 0;
    if (root == NULL)
        return NULL;
    result = strcmp(root->data->data->name, name);
    if (result == 0)
        return root->data;
    else if (result > 0)
        return searchByName(root->left, name);
    else
        return searchByName(root->right, name);
}

// ����� �� �������� �� ��������
NodeStudent* searchByAge(TreeNode* root, int age) {
    if (root == NULL)
        return NULL;
    if (root->data->data->age == age)
        return root->data;
    else if (root->data->data->age > age)
        return searchByAge(root->left, age);
    else
        return searchByAge(root->right, age);
}

// ����� �� �������� �� ID
NodeStudent* searchById(TreeNode* root, int id) {
    if (root == NULL)
        return NULL;
    if (root->data->data->id == id)
        return root->data;
    else if (root->data->data->id > id)
        return searchById(root->left, id);
    else
        return searchById(root->right, id);
}

// �������� ���� ������
void loadDB(StackStudents* stack) {
    Student* student;
    FILE * file = fopen("students.db", "rb");
    if (file != NULL) {
        while (!feof(file)) {
            student = malloc(sizeof(Student));
            if (fread(student, sizeof(Student), 1, file))
                pushStack(stack, student);
            else
                free(student);
        }
        fclose(file);
    }
}

/*
* Main function
*/
int main(int argc, char* argv[]) {
    #define SIZE 10
    int arr[SIZE] = {6,8,7,3,9,10,0,4,1,2};
    Node* tree = NULL;
    int i;
    TreeNode* searchTreeId = NULL;
    TreeNode* searchTreeAge = NULL;
    TreeNode* searchTreeName = NULL;
    StackStudents students;
    students.head = NULL;
    students.size = 0;

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
    printf("\nSearch 5 = %d\n", searchTree(tree, 5));

    writeDB();
    loadDB(&students);
    printf("\n��������� ���������: %d\n", students.size);
    printStudents(students.head);

    searchTreeId = getSearchTree(students.head, TYPE_TREE_BY_ID);
    searchTreeAge = getSearchTree(students.head, TYPE_TREE_BY_AGE);
    searchTreeName = getSearchTree(students.head, TYPE_TREE_BY_NAME);

    printf("\n������ ������ �� �����:\n");
    printTreeStudents(searchTreeName);
    printf("\n������ ������ �� id:\n");
    printTreeStudents(searchTreeId);
    printf("\n������ ������ �� ��������:\n");
    printTreeStudents(searchTreeAge);

    printf("\n����� �� ����� ���� ������:\n");
    printStudents(searchByName(searchTreeName, "���� ������"));
    printf("\n����� �� ��������� 21:\n");
    printStudents(searchByAge(searchTreeAge, 21));
    printf("\n����� �� ������ 10:\n");
    printStudents(searchById(searchTreeId, 10));


    getch();
    return 0;
}