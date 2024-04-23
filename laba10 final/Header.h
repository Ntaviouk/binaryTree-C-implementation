#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int number;
	struct Node *left = NULL;
	struct Node *right = NULL;
};

typedef struct Node TreeNode;

struct node
{
	TreeNode* number;
	struct node* next = NULL;
};

typedef struct node NODE;

struct sNode 
{
	TreeNode* t;
	struct sNode* next;
};

typedef struct sNode StackNode;

TreeNode* createbinaryTree(TreeNode *root, char* data);

int convertFromSevenTodecimal(char* number);

void convertToSevenSystem(int number);

void binaryTreeTraversal(TreeNode* root);

void insertToBinaryTree(TreeNode* root, char* data);

void printTreeTable(TreeNode* root);

void swapParentChild(TreeNode* root);

TreeNode* searchTreeNode(TreeNode* root, int number);

void addToQueue(TreeNode* num);

NODE* popQueue(NODE** head);

void levelOrderTraversal(TreeNode* root);

void swapParentChildWithoutRecurse(TreeNode* root);

void push(StackNode** top_ref, TreeNode* t);

TreeNode* pop(StackNode** top_ref);

bool isEmpty(StackNode* top);

void deleteBinaryTree(TreeNode* root);

void inOrderDelete(TreeNode* root);