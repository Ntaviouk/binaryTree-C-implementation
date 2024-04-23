#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

int main()
{
	printf("for file numbers1 : \n\n");
	TreeNode* root = NULL;
	char first[5] = "111";
	root = createbinaryTree(root, first);
	FILE* fl;
	fl = fopen("numbers1.txt", "r");
	if (!fl)
	{
		printf("no file\n\n");
		return 0;
	}
	char ptr = fgetc(fl);
	printf("numbers in 7 system as in file : ");
	printf("%d ", convertFromSevenTodecimal(first));
	while (!feof(fl))
	{
		char temp[10];
		int temp_counter = 0;
		while (ptr != '\n' && !feof(fl))
		{
			temp[temp_counter++] = ptr;
			ptr = fgetc(fl);
		}
		temp[temp_counter] = '\0';
		insertToBinaryTree(root, temp);
		printf("%d ", convertFromSevenTodecimal(temp));
		ptr = fgetc(fl);
	}
	printf("\n binary tree traversal : ");
	binaryTreeTraversal(root);
	printf("\n level order traversal : ");
	levelOrderTraversal(root);
	printf("\n tree table : \n");
	printTreeTable(root);
	printf("\n binary tree traversal : ");
	binaryTreeTraversal(root);
	//swapParentChild(root);
	swapParentChildWithoutRecurse(root);
	printf("\n changed func is done\n");
	printf("changed tree : ");
	binaryTreeTraversal(root);

	printf("\nsearch : ");
	if (searchTreeNode(root, 49))
	{
		printf("\nyest\n");
	}
	else
	{
		printf("\nnone\n");
	}
	printf("\n");
	deleteBinaryTree(root);
	


	printf("\n\nfor file numbers2 : \n\n");
	root = NULL;
	char firstNums2[5] = "100";
	root = createbinaryTree(root, firstNums2);
	//FILE* fl;
	fl = fopen("number2.txt", "r");
	if (!fl)
	{
		printf("no file\n\n");
		return 0;
	}
	ptr = fgetc(fl);
	printf("numbers in 7 system as in file : ");
	printf("%d ", convertFromSevenTodecimal(firstNums2));
	while (!feof(fl))
	{
		char temp[10];
		int temp_counter = 0;
		while (ptr != '\n' && !feof(fl))
		{
			temp[temp_counter++] = ptr;
			ptr = fgetc(fl);
		}
		temp[temp_counter] = '\0';
		insertToBinaryTree(root, temp);
		printf("%d ", convertFromSevenTodecimal(temp));
		ptr = fgetc(fl);
	}
	printf("\n binary tree traversal : ");
	binaryTreeTraversal(root);
	printf("\n level order traversal : ");
	levelOrderTraversal(root);
	printf("\n tree table : \n");
	printTreeTable(root);
	printf("\n binary tree traversal : ");
	binaryTreeTraversal(root);
	//swapParentChild(root);
	swapParentChildWithoutRecurse(root);
	printf("\n changed func is done\n");
	printf("changed tree : ");
	binaryTreeTraversal(root);

	printf("\nsearch : ");
	if (searchTreeNode(root, 49))
	{
		printf("\nyest\n");
	}
	else
	{
		printf("\nnone\n");
	}
	printf("\n");
	inOrderDelete(root);
	//deleteBinaryTree(root);
	return 0;
}