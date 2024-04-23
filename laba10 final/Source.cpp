#include "Header.h"

NODE* head = NULL;

int pow(int a, int b)
{
	int result = 1, temp = a;
	if (b == 0) return 1;
	for (int i = 0; i < b - 1; i++)
	{
		a *= temp;
	}
	return a;
}

int convertFromSevenTodecimal(char* number)
{
	int length = -1;
	int result = 0;
	char* ptr = number;
	while (*ptr++ != '\0') length += 1;
	ptr = number;
	while (*ptr != '\0')
	{
		result += (*ptr - '0') * pow(7, length--);
		ptr++;
	}
	return result;
}

void convertToSevenSystem(int num)
{
	if (num == 0) 
	{
		printf("0");
		return;
	}
	int binaryNum[20]; 
	int i = 0;

	for (; num > 0; )
	{
		binaryNum[i++] = num % 7;
		num /= 7;
	}
	for (int j = i - 1; j >= 0; j--)
		printf("%d", binaryNum[j]);
}


TreeNode* createbinaryTree(TreeNode *root, char* data)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	int newData = convertFromSevenTodecimal(data);
	newNode->number = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


void binaryTreeTraversal(TreeNode* root)
{
	if (root == NULL) return;
	printf("%d ", root->number);
	binaryTreeTraversal(root->left);
	binaryTreeTraversal(root->right);
}

void insertToBinaryTree(TreeNode* root, char* data)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	int newData = convertFromSevenTodecimal(data);
	newNode->number = newData;
	newNode->left = NULL;
	newNode->right = NULL;
	if (newData < root->number)
	{
		if (root->left == NULL)
		{
			root->left = newNode;
			return;
		}
		insertToBinaryTree(root->left, data);
	}
	else if(newData > root->number)
	{
		if (root->right == NULL)
		{
			root->right = newNode;
			return;
		}
		insertToBinaryTree(root->right, data);
	}
}

void printTreeTable(TreeNode* root)
{
	if (root == NULL) return;
	printTreeTable(root->right);
	printf("dec : %d seven : ", root->number);
	convertToSevenSystem(root->number);
	printf("\n");
	printTreeTable(root->left);
	
}

void swapParentChild(TreeNode* root)
{
	if (root == NULL) return;
	if (root->left == NULL && root->right && root->right->left == NULL)
	{
		int temp = root->number;
		root->number = root->right->number;
		TreeNode* temp_tree = (TreeNode*)malloc(sizeof(TreeNode));
		temp_tree->number = temp;
		temp_tree->left = NULL;
		temp_tree->right = NULL;
		root->left = temp_tree;
		free(root->right);
		root->right = NULL;
	}
	swapParentChild(root->left);
	swapParentChild(root->right);
}


TreeNode* searchTreeNode(TreeNode* root, int number)
{
	TreeNode* start = root;
	while (start != NULL)
	{
		if(start->number == number) return start;
		if (number > start->number) start = start->right;
		else start = start->left;
	}
	return NULL;
}

void addToQueue(TreeNode* num)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->number = num;
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
}

NODE* popQueue(NODE** head)
{
	if (head == NULL)
	{
		return NULL;
	}
	NODE* temp = *head;
	if (temp->next == NULL)
	{
		NODE* returnNode = temp;
		*head = NULL;
		return returnNode;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	NODE* tempReturn = temp->next;

	temp->next = NULL;

	return tempReturn;
}

void levelOrderTraversal(TreeNode* root)
{
	if (root == NULL) return;
	addToQueue(root);
	while (head)
	{
		TreeNode* temp = popQueue(&head)->number;
		printf("%d ", temp->number);
		if (temp->left) addToQueue(temp->left);
		if (temp->right) addToQueue(temp->right);
	}
}

void swapParentChildWithoutRecurse(TreeNode* root)
{
	//if (root->left == NULL && root->right && root->right->left == NULL)
	//{
	//	int temp = root->number;
	//	root->number = root->right->number;
	//	TreeNode* temp_tree = (TreeNode*)malloc(sizeof(TreeNode));
	//	temp_tree->number = temp;
	//	temp_tree->left = NULL;
	//	temp_tree->right = NULL;
	//	root->left = temp_tree;
	//	free(root->right);
	//	root->right = NULL;
	//}

	if (root == NULL) return;
	addToQueue(root);
	while (head)
	{
		TreeNode* tempRoot = popQueue(&head)->number;
		//printf("%d ", tempRoot->number);
		if (tempRoot->left == NULL && tempRoot->right && tempRoot->right->left == NULL)
		{
			int temp = tempRoot->number;
			tempRoot->number = tempRoot->right->number;
			TreeNode* temp_tree = (TreeNode*)malloc(sizeof(TreeNode));
			temp_tree->number = temp;
			temp_tree->left = NULL;
			temp_tree->right = NULL;
			tempRoot->left = temp_tree;
			free(tempRoot->right);
			tempRoot->right = NULL;
		}
		if (tempRoot->left) addToQueue(tempRoot->left);
		if (tempRoot->right) addToQueue(tempRoot->right);
	}
}

void push(StackNode** top_ref, TreeNode* t)
{
	StackNode* new_tNode
		= (StackNode*)malloc(sizeof(StackNode));

	if (new_tNode == NULL) {
		printf("Stack Overflow \n");
		getchar();
		exit(0);
	}
	new_tNode->t = t;
	new_tNode->next = (*top_ref);
	(*top_ref) = new_tNode;
}

TreeNode* pop(StackNode** top_ref)
{
	TreeNode* res;
	StackNode* top;

	if (isEmpty(*top_ref)) {
		printf("Stack Underflow \n");
		getchar();
		exit(0);
	}
	else {
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

bool isEmpty(StackNode* top)
{
	return (top == NULL) ? 1 : 0;
}

void deleteBinaryTree(TreeNode *root)
{
	if (root == NULL) return;
	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);
	free(root);
}

void inOrderDelete(TreeNode* root)
{
	TreeNode* current = root;
	StackNode* s = NULL;
	bool done = 0;

	while (!done)
	{
		if (current != NULL)
		{
			push(&s, current);
			current = current->right;
		}
		else
		{
			if (!isEmpty(s))
			{
				current = pop(&s);
				TreeNode* temp = current;
				printf("%d ", current->number);
				current = current->left;
				free(temp);
			}
			else
			{
				done = 1;
			}
		}
	}
}